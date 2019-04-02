#include "camera.h"

Camera::Camera() {
    origin_ = Vec3(0.0);
    lower_left_corner_ = Vec3(-2.0, -1.0, -1.0);
    horizontal_ = Vec3(4.0, 0.0, 0.0);
    vertical_ = Vec3(0.0, 2.0, 0.0);
}

Ray Camera::get_ray(float u, float v) {
    return {origin_, lower_left_corner_ + u*horizontal_ + v*vertical_};
}
