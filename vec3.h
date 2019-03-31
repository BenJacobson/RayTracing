#ifndef VEC3_H_
#define VEC3_H_

class Vec3 {
public:
    Vec3();
    Vec3(float x, float y, float z);

    float x() const;
    float y() const;
    float z() const;
    float r() const;
    float g() const;
    float b() const;
    float length() const;

private:
    float x_;
    float y_;
    float z_;
};

float dot(const Vec3& v1, const Vec3& v2);

Vec3 unit_vector(const Vec3& v);

Vec3 lerp(const Vec3& v1, const Vec3& v2, float t);

Vec3 operator*(float t, const Vec3& v);

Vec3 operator*(const Vec3& v, float t);

Vec3 operator/(const Vec3& v, float f);

Vec3 operator+(const Vec3& v1, const Vec3& v2);

Vec3 operator-(const Vec3& v1, const Vec3& v2);

#endif
