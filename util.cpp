#include "vec3.h"
#include "util.h"

#include <random>

namespace util {

    float clamp(float f, float low, float high) {
        if (f < low) {
            return low;
        }
        if (f > high) {
            return high;
        }
        return f;
    }

    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_real_distribution<> dist(0.0, 1.0);

    float random() {
        return dist(engine);
    }

    float abs(float f) {
        return f >= 0 ? f : -f;
    }

    Vec3 random_in_unit_sphere() {
        Vec3 p;
        do {
            p = 2.0*Vec3(random(), random(), random()) - Vec3(1.0);
        } while (abs(p.length()) >= 1.0);
        return p;
    }

    Vec3 reflect(const Vec3& v, const Vec3& normal) {
        return v - 2*dot(v, normal)*normal;
    }

    bool refract(const Vec3& v, const Vec3& n, float ni_over_nt, Vec3& refracted) {
        Vec3 uv = unit_vector(v);
        float dt = dot(uv, n);
        float discriminant = 1.0 - ni_over_nt*ni_over_nt*(1.0 - dt*dt);
        if (discriminant > 0) {
            refracted = ni_over_nt*(uv - n*dt) - n*sqrt(discriminant);
            return true;
        }
        return false;
    }
}
