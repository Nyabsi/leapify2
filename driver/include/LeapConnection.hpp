#ifndef LeapConnection_h__
#define LeapConnection_h__

#include <LeapHand.hpp>

#include <atomic>
#include <thread>

#include <LeapC.h>

class LeapConnection {
public:
	bool Initialize();
	void Start();
	void Stop();
	LeapHand getHand(vr::ETrackedControllerRole role);
private:
	void Update();

	LEAP_CONNECTION m_connection { nullptr };
	std::atomic<bool> m_running { false };
	std::thread m_thread { };
	std::atomic<int64_t> m_tracking_frame_id;
	std::atomic<LeapHand> m_leftHand { };
	std::atomic<LeapHand> m_rightHand { };
};

#endif // LeapConnection_h__