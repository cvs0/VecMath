#ifndef VECMATH_H
#define VECMATH_H

#include <cmath>

template <typename T>
class Vec3;

template <typename T>
class Vec4;

template <typename T>
class Mat4;

template <typename T>
class VecMath {
public:
    static T dot(const Vec3<T>& a, const Vec3<T>& b);
    static Vec3<T> cross(const Vec3<T>& a, const Vec3<T>& b);
    static Vec3<T> normalize(const Vec3<T>& v);
    static Vec3<T> add(const Vec3<T>& a, const Vec3<T>& b);
    static Vec3<T> subtract(const Vec3<T>& a, const Vec3<T>& b);
    static Vec3<T> multiply(const Vec3<T>& v, T scalar);
    static Vec3<T> multiply(const Vec3<T>& a, const Vec3<T>& b);
    static Vec3<T> project(const Vec3<T>& a, const Vec3<T>& b);
    static Vec3<T> reflect(const Vec3<T>& incident, const Vec3<T>& normal);
    static Vec3<T> lerp(const Vec3<T>& start, const Vec3<T>& end, T t);
    static Vec3<T> clamp(const Vec3<T>& v, T minVal, T maxVal);
    static Vec3<T> abs(const Vec3<T>& v);
    static Vec3<T> multiply(const Mat4<T>& matrix, const Vec3<T>& vector);

    static T dot(const Vec4<T>& a, const Vec4<T>& b);
    static Vec4<T> normalize(const Vec4<T>& v);
    static Vec4<T> add(const Vec4<T>& a, const Vec4<T>& b);
    static Vec4<T> subtract(const Vec4<T>& a, const Vec4<T>& b);
    static Vec4<T> multiply(const Vec4<T>& v, T scalar);
    static Vec4<T> multiply(const Vec4<T>& a, const Vec4<T>& b);
    static Vec4<T> project(const Vec4<T>& a, const Vec4<T>& b);
    static Vec4<T> reflect(const Vec4<T>& incident, const Vec4<T>& normal);
    static Vec4<T> lerp(const Vec4<T>& start, const Vec4<T>& end, T t);
    static Vec4<T> clamp(const Vec4<T>& v, T minVal, T maxVal);
    static Vec4<T> abs(const Vec4<T>& v);
    static Vec4<T> multiply(const Mat4<T>& matrix, const Vec4<T>& vector);

    static Mat4<T> transpose(const Mat4<T>& matrix);
    static Mat4<T> identity();
    static Mat4<T> scale(const Mat4<T>& matrix, T scaleX, T scaleY, T scaleZ);
    static Mat4<T> translate(const Mat4<T>& matrix, T translateX, T translateY, T translateZ);
    static Mat4<T> multiply(const Mat4<T>& a, const Mat4<T>& b);
};

#endif // VECMATH_H
