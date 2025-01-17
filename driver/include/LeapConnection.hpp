#ifndef LeapConnection_h__
#define LeapConnection_h__

#include <LeapHand.hpp>

#include <atomic>
#include <thread>
#include <functional>

#include <LeapC.h>

class LeapConnection {
public:
	bool Initialize();
	void SetCallback(vr::ETrackedControllerRole role, std::function<void(LeapHand)> callback);
	void Start();
	void Stop();
private:
	void Update();

	LEAP_CONNECTION m_connection { nullptr };
	std::atomic<bool> m_running { false };
	std::thread m_thread { };
	std::atomic<int64_t> m_tracking_frame_id { };
	std::function<void(LeapHand)> m_callback_left;
	std::function<void(LeapHand)> m_callback_right;
};

#endif // LeapConnection_h__