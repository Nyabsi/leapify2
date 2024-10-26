#pragma once

#include <openvr_driver.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

vr::HmdQuaternion_t EulerToQuaternion(double roll, double pitch, double yaw) 
{
    double cr = cos(roll * 0.5);
    double sr = sin(roll * 0.5);
    double cp = cos(pitch * 0.5);
    double sp = sin(pitch * 0.5);
    double cy = cos(yaw * 0.5);
    double sy = sin(yaw * 0.5);

    vr::HmdQuaternion_t result{};
    result.w = cr * cp * cy + sr * sp * sy;
    result.x = cr * sp * cy + sr * cp * sy;  // pitch
    result.y = cr * cp * sy - sr * sp * cy;  // yaw
    result.z = sr * cp * cy - cr * sp * sy;  // roll

    return result;
}

vr::HmdQuaternion_t operator*(const vr::HmdQuaternion_t& q, const vr::HmdQuaternion_t& r) 
{
    vr::HmdQuaternion_t result{};

    result.w = r.w * q.w - r.x * q.x - r.y * q.y - r.z * q.z;
    result.x = r.w * q.x + r.x * q.w - r.y * q.z + r.z * q.y;
    result.y = r.w * q.y + r.x * q.z + r.y * q.w - r.z * q.x;
    result.z = r.w * q.z - r.x * q.y + r.y * q.x + r.z * q.w;

    return result;
}