#ifndef DIFFUSE_H_
#define DIFFUSE_H_

#include "material.h"
#include "vec3.h"

class Diffuse: public Material {
public:
    Diffuse(const Vec3& albedo);
    bool scatter(const Ray& ray, const hit_record& record, Vec3& attenuation, Ray& scattered) const override;

private:
    Vec3 albedo_;
};

#endif