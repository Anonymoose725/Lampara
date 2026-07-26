#ifndef LAMPARA_VEC3_H
#define LAMPARA_VEC3_H

#include <cmath>
#include <iostream>

class vec3 {
public:
    // 3 coordinates
    double e[3];

    vec3() : e(0, 0, 0) {} // default
    vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

    // get components
    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    vec3& operator-() const { return vec3(-e[0], -e[1], -e[2]); } // reflect
    double operator[](int i) const { return e[i]; } // index coordinate
    double& operator[](int i) { return e[i]; }

    // vector addition
    vec3& operator+=(const vec3& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    // scalar multiplication
    vec3& operator*=(double c) {
        e[0] *= c;
        e[1] *= c;
        e[2] *= c;
        return *this;
    }

    vec3& operator/=(double c) {
        return *this *= (1/c); // single division operation
    }

    double length() const {
        return std::sqrt(length_squared());
    }

    double length_squared() const {
        return (e[0] * e[0]) + (e[1] * e[1]) + (e[2] * e[2]);
    }
};

// alias
using point3 = vec3;

// utilities

inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
} // output stream

inline vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v) { // hadamard product
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(double c, const vec3& v) { // scalar mult
    return vec3(c * v.e[0], c * v.e[1], c * v.e[2]);
}

inline vec3 operator*(const vec3& v, double c) {
    return c * v;
}

inline vec3 operator/(const vec3& v, double c) {
    return (1/c) * v;
}

inline vec3 cross(const vec3& u, const vec3& v) { // orthogonal vector
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline double dot(const vec3& u, const vec3& v) {
    return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] + v.e[2];
}

inline vec3 unit_vector(const vec3& v) {
    return v / v.length();
}

#endif //LAMPARA_VEC3_H