#include "ppm.h"
#include "ray.h"
#include "vec3.h"

#include <iostream>
#include <math.h>

float hit_sphere(const Vec3& center, float radius, const Ray& ray) {
    Vec3 oc = ray.origin() - center;
    float a = dot(ray.direction(), ray.direction());
    float b = 2.0 * dot(oc, ray.direction());
    float c = dot(oc, oc) - radius*radius;
    float discriminant = b*b - 4*a*c;
    if (discriminant < 0) {
        return -1.0;
    } else {
        return (-b - sqrt(discriminant)) / (2.0*a);
    }
}

Vec3 color(const Ray& ray) {
    const Vec3 sphere_center = Vec3(0.0, 0.0, -2.0);
    const Vec3 top_color = Vec3(0.0, 0.5, 1.0);
    const Vec3 bottom_color = Vec3(1.0, 0.5, 1.0);

    float t = hit_sphere(sphere_center, 1.0, ray);

    if (t > 0.0) {
        Vec3 normal = unit_vector(ray.point_at(t) - sphere_center);
        return 0.5 * (normal + Vec3(1.0));
    } else {
        Vec3 unit = ray.unit_vector();
        float y = 0.5 * (unit.y() + 1.0);
        return lerp(top_color, bottom_color, y);
    }
}

int main() {
    freopen("../out.ppm", "w", stdout);

    int height = 300;
    int width = 600;
    PPM ppm = PPM(height, width, 8);

    const Vec3 top_left_corner = Vec3(-2.0, 1.0, -1.0);
    const Vec3 horizontal = Vec3(4.0, 0.0, 0.0);
    const Vec3 vertical = Vec3(0.0, -2.0, 0.0);
    const Vec3 origin = Vec3(0.0, 0.0, 0.0);

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            float u = float(j) / float(width);
            float v = float(i) / float(height);
            Ray ray = Ray(origin, top_left_corner + u*horizontal + v*vertical);
            ppm.setPixel(i, j, color(ray));
        }
    }

    ppm.print();

    return 0;
}
