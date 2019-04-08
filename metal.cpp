#include "metal.h"
#include "util.h"

Metal::Metal(const Vec3& albedo, float fuzzy) {
    albedo_ = albedo;
    fuzzy_ = util::clamp(fuzzy, 0.0, 1.0);
}

bool Metal::scatter(const Ray& ray, const hit_record& record, Vec3& attenuation, Ray& scattered) const {
    Vec3 reflected = util::reflect(unit_vector(ray.direction()), record.normal);
    scattered = Ray(record.p, reflected + fuzzy_*util::random_in_unit_sphere());
    attenuation = albedo_;
    return dot(scattered.direction(), record.normal) > 0;
}
