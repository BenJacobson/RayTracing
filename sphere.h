#ifndef SPHERE_H_
#define SPHERE_H_

#include "entity.h"

class Sphere: public Entity {
public:
    Sphere(Vec3 center, float radius);
    bool hit(const Ray& ray, float t_min, float t_max, hit_record& record) const override;

private:
    Vec3 center_;
    float radius_;
};

#endif