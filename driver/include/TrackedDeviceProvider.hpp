#ifndef TrackedDeviceProvider_h__
#define TrackedDeviceProvider_h__

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
};

#endif // TrackedDeviceProvider_h__