#ifndef UTIL_H_
#define UTIL_H_

namespace util {
    float clamp(float f, float low, float high);
    float random();
    Vec3 random_in_unit_sphere();
    Vec3 reflect(const Vec3& v, const Vec3& normal);
    bool refract(const Vec3& v, const Vec3& n, float ni_over_nt, Vec3& refracted);
}

#endif