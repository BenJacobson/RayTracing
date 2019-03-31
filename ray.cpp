#include "ray.h"
#include "vec3.h"

Ray::Ray(const Vec3& from, const Vec3& to) {
    this->from = from;
    this->to = to;
}

Vec3 Ray::point_at(float t) const {
    return this->from + t*this->to;
}

Vec3 Ray::unit_vector() const {
    return ::unit_vector(this->to - this->from);
}
