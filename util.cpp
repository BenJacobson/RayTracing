#include "vec3.h"
#include "util.h"

#include <random>

namespace util {

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

}
