#ifndef ENTITY_LIST_H_
#define ENTITY_LIST_H_

#include "entity.h"

#include <vector>

class EntityList: public Entity {
public:
    EntityList() = default;
    void push(Entity *entity);
    bool hit(const Ray& ray, float t_min, float t_max, hit_record& record) const override;

private:
    std::vector<Entity*> entities_;
};

#endif