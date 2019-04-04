#ifndef METAL_H_
#define METAL_H_

#include "material.h"
#include "vec3.h"

class Metal: public Material {
public:
    Metal(const Vec3& albedo, float fuzzy);
    bool scatter(const Ray& ray, const hit_record& record, Vec3& attenuation, Ray& scattered) const override;

private:
    Vec3 albedo_;
    float fuzzy_;
};

#endif