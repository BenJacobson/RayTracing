#include "vec3.h"

#include <math.h>

Vec3::Vec3() : Vec3(0) {}

Vec3::Vec3(float a) : Vec3(a, a, a) {}

Vec3::Vec3(float x, float y, float z) {
    this->x_ = x;
    this->y_ = y;
    this->z_ = z;
}

float Vec3::x() const {
    return x_;
}

float Vec3::y() const {
    return y_;
}

float Vec3::z() const {
    return z_;
}

float Vec3::r() const {
    return x_;
}

float Vec3::g() const {
    return y_;
}

float Vec3::b() const {
    return z_;
}

float Vec3::length() const {
    return ::sqrt(x_*x_ + y_*y_ + z_*z_);
}

Vec3 Vec3::sqrt() const {
    return {::sqrt(x_), ::sqrt(y_), ::sqrt(z_)};
}

Vec3& Vec3::operator*=(float f) {
    x_ *= f;
    y_ *= f;
    z_ *= f;
    return *this;
}


Vec3& Vec3::operator+=(Vec3 const& v) {
    x_ += v.x();
    y_ += v.y();
    z_ += v.z();
    return *this;
}


float dot(const Vec3& v1, const Vec3& v2) {
    return v1.x()*v2.x() + v1.y()*v2.y() + v1.z()*v2.z();
}

Vec3 unit_vector(const Vec3& v) {
    return 1 / v.length() * v;
}

Vec3 lerp(const Vec3& v1, const Vec3& v2, float t) {
    return (1.0-t)*v1 + t*v2;
}

Vec3 operator*(float t, const Vec3& v) {
    return {t*v.x(), t*v.y(), t*v.z()};
}

Vec3 operator*(const Vec3& v, float t) {
    return t*v;
}

Vec3 operator+(const Vec3& v1, const Vec3& v2) {
    return {v1.x()+v2.x(), v1.y()+v2.y(), v1.z()+v2.z()};
}

Vec3 operator-(const Vec3& v1, const Vec3& v2) {
    return {v1.x()-v2.x(), v1.y()-v2.y(), v1.z()-v2.z()};
}
