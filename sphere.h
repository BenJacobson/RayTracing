#ifndef SPHERE_H_
#define SPHERE_H_

#include "entity.h"

class Sphere: public Entity {
public:
    Sphere(Vec3 center, const Material *material, float radius);
    const Material* hit(const Ray& ray, float t_min, float t_max, hit_record& record) const override;

private:
    Vec3 center_;
    const Material* material_;
    float radius_;
};

#endif