#ifndef TrackedDeviceProvider_h__
#define TrackedDeviceProvider_h__

#include <LeapConnection.hpp>

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
    LeapConnection m_leap_connection { };
};

#endif // TrackedDeviceProvider_h__