#ifndef MATERIAL_H_
#define MATERIAL_H_

#include "hit_record.h"
#include "ray.h"

class Material {
public:
    virtual bool scatter(const Ray& ray, const hit_record& record, Vec3& attenuation, Ray& scattered) const = 0;
};

#endif