#ifndef CAMERA_H_
#define CAMERA_H_

#include "ray.h"

class Camera {
public:
    Camera();
    Ray get_ray(float u, float v);

private:
    Vec3 origin_;
    Vec3 lower_left_corner_;
    Vec3 horizontal_;
    Vec3 vertical_;
};

#endif