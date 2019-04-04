#ifndef HIT_RECORD_H_
#define HIT_RECORD_H_

#include "vec3.h"

struct hit_record {
    float t{};
    Vec3 p;
    Vec3 normal;
};

#endif