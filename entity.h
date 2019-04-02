#ifndef ENTITY_H_
#define ENTITY_H_

#include "ray.h"

struct hit_record {
    float t{};
    Vec3 p;
    Vec3 normal;
};

class Entity {
public:
    virtual bool hit(const Ray& ray, float t_min, float t_max, hit_record& record) const = 0;
};

#endif