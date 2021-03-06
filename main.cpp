#include "camera.h"
#include "diffuse.h"
#include "entity.h"
#include "entity_list.h"
#include "glass.h"
#include "material.h"
#include "metal.h"
#include "ppm.h"
#include "ray.h"
#include "sphere.h"
#include "util.h"
#include "vec3.h"

#include "omp.h"

#include <chrono>
#include <iostream>
#include <math.h>

const int MAX_DEPTH = 5;
const int NUM_SMALL_BALLS = 400;
const float SMALL_BALL_RADIUS = 0.1;
const float LARGE_BALL_RADIUS = 0.5;
const float GROUND_HEIGHT = -0.75;

Vec3 color(const Ray& ray, Entity& world, int depth) {
    hit_record record;
    const Material* material_hit = world.hit(ray, 0.001, MAXFLOAT, record);
    if (material_hit) {
        Ray scattered;
        Vec3 attenuation;
        bool shouldContinue = material_hit->scatter(ray, record, attenuation, scattered);
        if (depth < MAX_DEPTH && shouldContinue) {
            return attenuation * color(scattered, world, depth+1);
        } else {
            return {0.0};
        }
    }

    const Vec3 top_color = Vec3(0.6, 0.6, 1.0);
    const Vec3 bottom_color = Vec3(0.8, 0.8, 1.0);
    float y = 0.5 * (-ray.direction().y() + 1.0);
    return lerp(top_color, bottom_color, y);
}

int main() {
    freopen("../out.ppm", "w", stdout);
    auto start = std::chrono::high_resolution_clock::now();

    int height = 300;
    int width = 600;
    int samples = 200;
    PPM ppm = PPM(height, width, 8);

    Camera camera(width, height);
    EntityList world;

    // Ground
    world.push(new Sphere(Vec3(0.0, GROUND_HEIGHT-1000.0, -1.0), new Diffuse(Vec3(0.5, 0.5, 0.5)), 1000.0));

    // Large Spheres
    world.push(new Sphere(Vec3(-0.7, GROUND_HEIGHT+LARGE_BALL_RADIUS, -4.5),
            new Diffuse(Vec3(0.8, 0.5, 0.3)), LARGE_BALL_RADIUS));
    world.push(new Sphere(Vec3(-0.1, GROUND_HEIGHT+LARGE_BALL_RADIUS, -3.5),
            new Glass(1.5), LARGE_BALL_RADIUS));
    world.push(new Sphere(Vec3(0.5, GROUND_HEIGHT+LARGE_BALL_RADIUS, -2.5),
            new Metal(Vec3(0.5, 0.5, 0.5), 0.0), LARGE_BALL_RADIUS));

    for (int i = 0; i < NUM_SMALL_BALLS; ++i) {
        Material *material;
        float material_type = util::random();
        if (material_type < 0.1) {
            material = new Glass(1.5);
        } else if (material_type < 0.5) {
            material = new Metal(Vec3(util::random(), util::random(), util::random()), 0.0);
        } else {
            material = new Diffuse(Vec3(util::random(), util::random(), util::random()));
        }
        world.push(new Sphere(Vec3(10.0f*(0.5f-util::random()), GROUND_HEIGHT+SMALL_BALL_RADIUS, -10.0f*util::random()),
                material, SMALL_BALL_RADIUS));
    }

    #pragma omp parallel for collapse(2)
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

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cerr << elapsed.count() << std::endl;

    return 0;
}
