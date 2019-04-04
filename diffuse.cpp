#include "diffuse.h"
#include "util.h"

Diffuse::Diffuse(const Vec3 &albedo) {
    albedo_ = albedo;
}

bool Diffuse::scatter(const Ray &ray, const hit_record &record, Vec3 &attenuation, Ray &scattered) const {
    Vec3 target = record.p + record.normal + util::random_in_unit_sphere();
    scattered = Ray(record.p, target - record.p);
    attenuation = albedo_;
    return true;
}
