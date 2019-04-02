#include "camera.h"
#include "entity.h"
#include "entity_list.h"
#include "ppm.h"
#include "ray.h"
#include "sphere.h"
#include "vec3.h"

#include <iostream>
#include <math.h>
#include <random>

Vec3 color(const Ray& ray, Entity& world) {
    hit_record record;
    if (world.hit(ray, 0.0, MAXFLOAT, record)) {
        return 0.5 * (record.normal + Vec3(1.0));
    } else {
        const Vec3 top_color = Vec3(0.0, 0.5, 1.0);
        const Vec3 bottom_color = Vec3(1.0, 0.5, 1.0);
        Vec3 unit = ray.unit_vector();
        float y = 0.5 * (unit.y() + 1.0);
        return lerp(top_color, bottom_color, y);
    }
}

int main() {
    freopen("../out.ppm", "w", stdout);

    int height = 300;
    int width = 600;
    int samples = 100;
    PPM ppm = PPM(height, width, 8);

    Camera camera;

    EntityList world;
    world.push(new Sphere(Vec3(0.0, 0.0, -1.0), 0.5));
    world.push(new Sphere(Vec3(0.0, -100.5, -1.0), 100.0));

    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_real_distribution<> dist(0.0, 1.0);

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            Vec3 pixel_color;
            for (int s = 0; s < samples; ++s) {
                float u = float(j + dist(engine)) / float(width);
                float v = float(height - i - dist(engine)) / float(height);
                pixel_color += color(camera.get_ray(u, v), world);
            }
            pixel_color *= 1.0 / float(samples);
            ppm.setPixel(i, j, pixel_color);
        }
    }

    ppm.print();

    return 0;
}
