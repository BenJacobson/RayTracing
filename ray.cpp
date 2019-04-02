#include "ray.h"
#include "vec3.h"

Ray::Ray(const Vec3& origin, const Vec3& direction) {
    origin_ = origin;
    direction_ = direction;
}

Vec3 Ray::origin() const {
    return origin_;
}

Vec3 Ray::direction() const {
    return direction_;
}

Vec3 Ray::point_at(float t) const {
    return origin_ + t*direction_;
}
