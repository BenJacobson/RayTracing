#ifndef RAY_H_
#define RAY_H_

#include "vec3.h"

class Ray {
public:
    Ray(const Vec3& from, const Vec3& to);
    Vec3 point_at(float t) const;
    Vec3 unit_vector() const;

private:
    Vec3 from = Vec3();
    Vec3 to = Vec3();
};

#endif