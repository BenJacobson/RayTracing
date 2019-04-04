#ifndef ENTITY_H_
#define ENTITY_H_

#include "hit_record.h"
#include "material.h"
#include "ray.h"

class Entity {
public:
    virtual const Material* hit(const Ray& ray, float t_min, float t_max, hit_record& record) const = 0;
};

#endif