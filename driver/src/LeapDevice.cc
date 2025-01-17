#include <LeapDevice.hpp>
#include <LeapHand.hpp>

#include <openvr_driver.h>

LeapDevice::LeapDevice(vr::ETrackedControllerRole role)
{
    if (role == vr::TrackedControllerRole_LeftHand)
        m_serial = "Leap-Serial-left";
    else 
        m_serial = "Leap-Serial-Right";
}

vr::EVRInitError LeapDevice::Activate(uint32_t unObjectId)
{
    m_connected.exchange(true);

    return vr::VRInitError_None;
}

void LeapDevice::Deactivate()
{
    m_connected.exchange(false);
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
    if (!m_connected) {
        vr::VRServerDriverHost()->TrackedDeviceAdded(m_serial.c_str(), vr::TrackedDeviceClass_Controller, this);
    } else {

    }
}