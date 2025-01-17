#ifndef LeapDevice_h__
#define LeapDevice_h__

#include <openvr_driver.h>
#include <LeapHand.hpp>

class LeapDevice : public vr::ITrackedDeviceServerDriver {
public:
    LeapDevice(vr::ETrackedControllerRole role);

	vr::EVRInitError Activate(uint32_t unObjectId);
	void Deactivate();
	void EnterStandby();
	void* GetComponent(const char* pchComponentNameAndVersion);
	void DebugRequest(const char* pchRequest, char* pchResponseBuffer, uint32_t unResponseBufferSize);
	vr::DriverPose_t GetPose();

public:
    void Tick();
    void Update(LeapHand& hand);

private:

};

#endif // LeapDevice_h__