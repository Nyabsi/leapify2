#include <TrackedDeviceProvider.hpp>

vr::EVRInitError TrackedDeviceProvider::Init(vr::IVRDriverContext* pDriverContext)
{
	VR_INIT_SERVER_DRIVER_CONTEXT(pDriverContext);

	return vr::VRInitError_None;
}

void TrackedDeviceProvider::Cleanup()
{
	VR_CLEANUP_SERVER_DRIVER_CONTEXT();
}

void TrackedDeviceProvider::RunFrame()
{

}