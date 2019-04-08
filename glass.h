#ifndef GLASS_H_
#define GLASS_H_

#include "material.h"

class Glass: public Material {
public:
    Glass(float refraction);
    bool scatter(const Ray& ray, const hit_record& record, Vec3& attenuation, Ray& scattered) const override;

private:
    float refraction_;

    float schlick(float cosine) const;
};

#endif