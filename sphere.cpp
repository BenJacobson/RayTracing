#include "sphere.h"

#include <math.h>

Sphere::Sphere(Vec3 center, const Material* material, float radius) {
    center_ = center;
    material_ = material;
    radius_ = radius;
}

const Material* Sphere::hit(const Ray& ray, float t_min, float t_max, hit_record& record) const {
    Vec3 oc = ray.origin() - center_;
    float a = dot(ray.direction(), ray.direction());
    float b = dot(oc, ray.direction());
    float c = dot(oc, oc) - radius_*radius_;
    float discriminant = b*b - a*c;
    if (discriminant > 0) {
        float low = (-b - sqrt(discriminant)) / a;
        if (low < t_max && low > t_min) {
            record.t = low;
            record.p = ray.point_at(low);
            record.normal = 1 / radius_ * (record.p - center_);
            return material_;
        }
        float high = (-b + sqrt(discriminant)) / a;
        if (high < t_max && high > t_min) {
            record.t = high;
            record.p = ray.point_at(high);
            record.normal = 1 / radius_ * (record.p - center_);
            return material_;
        }
    }
    return nullptr;
}
