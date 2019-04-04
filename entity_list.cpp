#include "entity_list.h"

void EntityList::push(Entity *entity) {
    entities_.push_back(entity);
}

const Material* EntityList::hit(const Ray& ray, float t_min, float t_max, hit_record& record) const {
    record.t = t_max;
    const Material* material = nullptr;

    for (const auto entity : entities_) {
        const Material *material_hit = entity->hit(ray, t_min, record.t, record);
        if (material_hit) {
            material = material_hit;
        }
    }

    return material;
}
