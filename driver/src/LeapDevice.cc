#include <LeapDevice.hpp>
#include <LeapHand.hpp>

#include <openvr_driver.h>

LeapDevice::LeapDevice(vr::ETrackedControllerRole role)
{

}

vr::EVRInitError LeapDevice::Activate(uint32_t unObjectId)
{
    return vr::VRInitError_None;
}

void LeapDevice::Deactivate()
{

}

void LeapDevice::EnterStandby()
{

}

void* LeapDevice::GetComponent(const char* pchComponentNameAndVersion)
{
    return nullptr;
}

void LeapDevice::DebugRequest(const char* pchRequest, char* pchResponseBuffer, uint32_t unResponseBufferSize)
{

}

vr::DriverPose_t LeapDevice::GetPose()
{
    return vr::DriverPose_t();
}

void LeapDevice::Tick()
{

}

void LeapDevice::Update(LeapHand& hand)
{

}