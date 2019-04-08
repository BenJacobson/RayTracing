#include "glass.h"
#include "util.h"

#include <math.h>

Glass::Glass(float refraction) {
    refraction_ = refraction;
}

bool Glass::scatter(const Ray& ray, const hit_record& record, Vec3& attenuation, Ray& scattered) const {
    Vec3 reflected = util::reflect(ray.direction(), record.normal);
    attenuation = Vec3(1.0);

    Vec3 outward_normal;
    float ni_over_nt, cosine;
    if (dot(ray.direction(), record.normal) > 0) {
        ni_over_nt = refraction_;
        outward_normal = -record.normal;
        cosine = refraction_ * dot(ray.direction(), record.normal) / ray.direction().length();
    } else {
        ni_over_nt = 1 / refraction_;
        outward_normal = record.normal;
        cosine = -dot(ray.direction(), record.normal) / ray.direction().length();
    }

    Vec3 refracted;
    float reflect_prob;
    if (util::refract(ray.direction(), outward_normal, ni_over_nt, refracted)) {
        reflect_prob = schlick(cosine);
    } else {
        reflect_prob = 1.0;
    }

    if (util::random() < reflect_prob) {
        scattered = Ray(record.p, reflected);
    } else {
        scattered = Ray(record.p, refracted);
    }
    return true;
}

float Glass::schlick(float cosine) const {
    float r0 = (1 - refraction_) / (1 + refraction_);
    r0 = r0*r0;
    return r0 + (1-r0)*pow((1-cosine), 5);
}
