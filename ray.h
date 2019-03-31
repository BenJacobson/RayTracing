#ifndef RAY_H_
#define RAY_H_

#include "vec3.h"

class Ray {
public:
    Ray(const Vec3& origin, const Vec3& direction);
    Vec3 origin() const;
    Vec3 direction() const;
    Vec3 point_at(float t) const;
    Vec3 unit_vector() const;

private:
    Vec3 origin_ = Vec3();
    Vec3 direction_ = Vec3();
};

#endif