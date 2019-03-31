#include <iostream>
#include "ppm.h"
#include "ray.h"
#include "vec3.h"

bool hit_sphere(const Vec3& center, float radius, const Ray& ray) {
    Vec3 oc = ray.origin() - center;
    float a = dot(ray.direction(), ray.direction());
    float b = 2.0 * dot(oc, ray.direction());
    float c = dot(oc, oc) - radius*radius;
    float discriminant = b*b - 4*a*c;
    return discriminant > 0;
}

int main() {
    freopen("../out.ppm", "w", stdout);

    int height = 300;
    int width = 600;
    PPM ppm = PPM(height, width);

    const Vec3 lower_left_corner = Vec3(-2.0, -1.0, -1.0);
    const Vec3 horizontal = Vec3(4.0, 0.0, 0.0);
    const Vec3 vertical = Vec3(0.0, 2.0, 0.0);
    const Vec3 origin = Vec3(0.0, 0.0, 0.0);
    const Vec3 sphere_center = Vec3(0.0, 0.0, -2.0);

    const Vec3 top_color = Vec3(1.0, 0.0, 0.0);
    const Vec3 bottom_color = Vec3(0.0, 0.0, 1.0);
    const Vec3 sphere_color = Vec3(0.0, 1.0, 0.0);

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            float u = float(j) / float(width);
            float v = float(i) / float(height);
            Ray ray = Ray(origin, lower_left_corner + u*horizontal + v*vertical);
            Vec3 unit = ray.unit_vector();
            float t = (unit.y() + 1.0) * 0.5;
            Vec3 color = hit_sphere(sphere_center, 1.0, ray) ? sphere_color : lerp(top_color, bottom_color, t);
            ppm.setPixel(i, j, int(255.99*color.r()), int(255.99*color.g()), int(255.99*color.b()));
        }
    }

    ppm.print();

    return 0;
}
