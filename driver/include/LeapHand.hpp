#ifndef LeapHand_h__
#define LeapHand_h__

#include <LeapC.h>
#include <openvr_driver.h>

struct LeapHand
{
	vr::ETrackedControllerRole role{ vr::TrackedControllerRole_Invalid };
	union {
		struct {
			LEAP_DIGIT thumb;
			LEAP_DIGIT index;
			LEAP_DIGIT middle;
			LEAP_DIGIT ring;
			LEAP_DIGIT pinky;
		};
		LEAP_DIGIT digits[5] { 0 };
	};
	LEAP_PALM palm { 0 };
	LEAP_BONE arm { 0 };
};

#endif // LeapHand_h__