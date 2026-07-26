#ifndef LAMPARA_RAY_H
#define LAMPARA_RAY_H
#include "vec3.h"

class ray {
private:
    point3 orig;
    vec3 dir;
public:
    ray() {}
    // recall point3 is an alias for vec3
    ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}

    // const before relates to read-only return type, const after means called-on object is read-only by function
    const point3& origin() const { return orig; }
    const vec3& direction() const { return dir; }

    // P(t) = A + tb
    point3 at(double t) {
        return orig + (t * dir);
    }
};

#endif //LAMPARA_RAY_H