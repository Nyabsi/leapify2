#ifndef TrackedDeviceProvider_h__
#define TrackedDeviceProvider_h__

#include <LeapConnection.hpp>
#include <LeapHand.hpp>
#include <LeapDevice.hpp>

#include <openvr_driver.h>

class TrackedDeviceProvider : public vr::IServerTrackedDeviceProvider {
public:
    ~TrackedDeviceProvider() { }

    vr::EVRInitError Init(vr::IVRDriverContext* pDriverContext);

    void Cleanup();

    const char* const* GetInterfaceVersions() { return vr::k_InterfaceVersions; }

    void RunFrame();

    bool ShouldBlockStandbyMode() { return false; }

    void EnterStandby() { }
    void LeaveStandby() { }

private:
    void CallbackLeft(LeapHand hand);
    void CallbackRight(LeapHand hand);

private:
    LeapConnection m_leap_connection { };
    LeapDevice m_hand_left { vr::TrackedControllerRole_LeftHand };
    LeapDevice m_hand_right { vr::TrackedControllerRole_RightHand };
};

#endif // TrackedDeviceProvider_h__