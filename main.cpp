#include "camera.h"
#include "diffuse.h"
#include "entity.h"
#include "entity_list.h"
#include "material.h"
#include "ppm.h"
#include "ray.h"
#include "sphere.h"
#include "util.h"
#include "vec3.h"

#include <iostream>
#include <math.h>

const int max_depth = 50;

Vec3 color(const Ray& ray, Entity& world, int depth) {
    hit_record record;
    const Material* material_hit = world.hit(ray, 0.001, MAXFLOAT, record);
    if (material_hit) {
        Ray scattered;
        Vec3 attenuation;
        bool shouldContinue = material_hit->scatter(ray, record, attenuation, scattered);
        if (depth < max_depth && shouldContinue) {
            return attenuation * color(scattered, world, depth+1);
        } else {
            return {0.0};
        }
    }

    const Vec3 top_color = Vec3(1.0, 1.0, 1.0);
    const Vec3 bottom_color = Vec3(1.0, 1.0, 1.0);
    float y = 0.5 * (-ray.direction().y() + 1.0);
    return lerp(top_color, bottom_color, y);
}

int main() {
    freopen("../out.ppm", "w", stdout);

    int height = 300;
    int width = 600;
    int samples = 100;
    PPM ppm = PPM(height, width, 8);

    Camera camera;

    const Diffuse diffuseMaterial(Vec3(0.8, 0.5, 0.3));

    EntityList world;
    world.push(new Sphere(Vec3(0.0, 0.0, -1.0), &diffuseMaterial, 0.5));
    world.push(new Sphere(Vec3(0.0, -100.5, -1.0), &diffuseMaterial, 100.0));


    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            Vec3 pixel_color;
            for (int s = 0; s < samples; ++s) {
                float u = float(j + util::random()) / float(width);
                float v = float(height - i - util::random()) / float(height);
                pixel_color += color(camera.get_ray(u, v), world, 0);
            }
            pixel_color *= 1.0 / float(samples);
            ppm.setPixel(i, j, pixel_color.sqrt());
        }
    }

    ppm.print();

    return 0;
}
