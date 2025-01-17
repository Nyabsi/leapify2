#include <LeapConnection.hpp>
#include <LeapHand.hpp>

#include <LeapC.h>

using namespace std::chrono_literals;

bool LeapConnection::Initialize()
{
	eLeapRS result {};

	LeapCreateConnection(nullptr, &m_connection);

	result = LeapOpenConnection(m_connection);

	return result == eLeapRS::eLeapRS_Success;
}

void LeapConnection::Start()
{
	m_running.exchange(true);

	m_thread = std::thread(&LeapConnection::Update, this);
	m_thread.detach();
}

void LeapConnection::Stop()
{
	m_running.exchange(false);
	
	if (m_thread.joinable())
		m_thread.join();
}

LeapHand LeapConnection::getHand(vr::ETrackedControllerRole role)
{
	switch (role)
	{
		case vr::TrackedControllerRole_LeftHand:
			return m_left_hand;
		case vr::TrackedControllerRole_RightHand:
			return m_right_hand;
		default:
			break;
	}
}

void LeapConnection::Update()
{
	eLeapRS result { };

	while (m_running.load())
	{
		LEAP_CONNECTION_MESSAGE message { };
		result = LeapPollConnection(m_connection, 100, &message);

		if (result == eLeapRS::eLeapRS_Timeout)
			continue;

		// I don't care if you have Leapmotion connected or not
		// So I will be only handling "eLeapEventType_Tracking"
		if (message.type == eLeapEventType_Tracking)
		{
			LEAP_TRACKING_EVENT event = *message.tracking_event;

			// event.tracking_frame_id increments each time it's received
			// if the application is running slowly it will do an repeat
			// so we're comparing the "tracking_frame_id"
			// with the last "tracking_frame_id" to make sure it is not sent twice
			if (m_tracking_frame_id.load() != event.tracking_frame_id)
			{
				for (uint32_t i = 0; i < event.nHands; i++)
				{
					auto& hand = event.pHands[i];

					LeapHand data {};

					data.role = static_cast<vr::ETrackedControllerRole>(hand.type + 1);
					memcpy(&data.digits, &hand.digits, sizeof(data.digits));
					memcpy(&data.digits, &hand.palm, sizeof(data.palm));
					memcpy(&data.digits, &hand.arm, sizeof(data.arm));
					
					// older LeapSDK SDK could track more than one pair of hands
					// This is no longer the case, there is always at Left/Right pair
					switch (hand.id)
					{
						case eLeapHandType_Left:
						{
							m_left_hand.exchange(data);
							break;
						}
						case eLeapHandType_Right:
						{
							m_right_hand.exchange(data);
							break;
						}
						default:
							break;
					}
				}

				m_tracking_frame_id.exchange(event.tracking_frame_id);
			}
		}

		std::this_thread::sleep_for(1ms); // to prevent from CPU utilization going through the roof.
	}
}
