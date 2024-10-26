#include <TrackedDeviceProvider.hpp>

vr::EVRInitError TrackedDeviceProvider::Init(vr::IVRDriverContext* pDriverContext)
{
	VR_INIT_SERVER_DRIVER_CONTEXT(pDriverContext);

	if (m_leap_connection.Initialize())
		m_leap_connection.Start();

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