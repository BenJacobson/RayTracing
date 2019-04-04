#ifndef UTIL_H_
#define UTIL_H_

namespace util {
    float clamp(float f, float low, float high);
    float random();
    Vec3 random_in_unit_sphere();
}

#endif