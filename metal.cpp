#include "metal.h"
#include "util.h"

Metal::Metal(const Vec3& albedo, float fuzzy) {
    albedo_ = albedo;
    fuzzy_ = util::clamp(fuzzy, 0.0, 1.0);
}

Vec3 reflect(const Vec3& v, const Vec3& normal) {
    return v - 2*dot(v, normal)*normal;
}

bool Metal::scatter(const Ray& ray, const hit_record& record, Vec3& attenuation, Ray& scattered) const {
    Vec3 reflected = reflect(unit_vector(ray.direction()), record.normal);
    scattered = Ray(record.p, reflected + fuzzy_*util::random_in_unit_sphere());
    attenuation = albedo_;
    return dot(scattered.direction(), record.normal) > 0;
}
