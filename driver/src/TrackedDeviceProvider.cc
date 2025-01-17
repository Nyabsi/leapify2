#include <TrackedDeviceProvider.hpp>

#include <openvr_driver.h>

vr::EVRInitError TrackedDeviceProvider::Init(vr::IVRDriverContext* pDriverContext)
{
	VR_INIT_SERVER_DRIVER_CONTEXT(pDriverContext);

	if (m_leap_connection.Initialize())
	{
		m_leap_connection.SetCallback(vr::TrackedControllerRole_LeftHand, [this](LeapHand hand) { CallbackLeft(hand); });
		m_leap_connection.SetCallback(vr::TrackedControllerRole_RightHand, [this](LeapHand hand) { CallbackRight(hand); });
		m_leap_connection.Start();
	}

	return vr::VRInitError_None;
}

void TrackedDeviceProvider::Cleanup()
{
	m_leap_connection.Stop();

	VR_CLEANUP_SERVER_DRIVER_CONTEXT();
}

void TrackedDeviceProvider::RunFrame()
{

}

void TrackedDeviceProvider::CallbackLeft(LeapHand hand)
{
	m_hand_left.Update(hand);
}

void TrackedDeviceProvider::CallbackRight(LeapHand hand)
{
	m_hand_right.Update(hand);
}