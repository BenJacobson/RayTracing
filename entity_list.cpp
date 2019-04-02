#include "entity_list.h"

void EntityList::push(Entity *entity) {
    entities_.push_back(entity);
}

bool EntityList::hit(const Ray& ray, float t_min, float t_max, hit_record& record) const {
    hit_record closest_hit;
    closest_hit.t = t_max;
    bool found_hit = false;

    for (const auto entity : entities_) {
        if (entity->hit(ray, t_min, closest_hit.t, closest_hit)) {
            found_hit = true;
        }
    }

    if (found_hit) {
        record = closest_hit;
    }

    return found_hit;
}
