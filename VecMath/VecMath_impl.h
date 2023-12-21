#ifndef VECMATH_IMPL_H
#define VECMATH_IMPL_H

#include "VecMath.h"

template <typename T>
class Vec3 {
public:
    T x, y, z;

    Vec3() : x(0.0f), y(0.0f), z(0.0f) {}
    Vec3(T x, T y, T z) : x(x), y(y), z(z) {}

    T dot(const Vec3<T>& b) const {
        return VecMath<T>::dot(*this, b);
    }

    Vec3<T> cross(const Vec3<T>& b) const {
        return VecMath<T>::cross(*this, b);
    }

    Vec3<T> normalize() const {
        return VecMath<T>::normalize(*this);
    }

    Vec3<T> add(const Vec3<T>& b) const {
        return VecMath<T>::add(*this, b);
    }

    Vec3<T> subtract(const Vec3<T>& b) const {
        return VecMath<T>::subtract(*this, b);
    }

    Vec3<T> multiply(T scalar) const {
        return VecMath<T>::multiply(*this, scalar);
    }

    Vec3<T> multiply(const Vec3<T>& b) const {
        return VecMath<T>::multiply(*this, b);
    }

    Vec3<T> project(const Vec3<T>& b) const {
        return VecMath<T>::project(*this, b);
    }

    Vec3<T> reflect(const Vec3<T>& normal) const {
        return VecMath<T>::reflect(*this, normal);
    }

    Vec3<T> lerp(const Vec3<T>& end, T t) const {
        return VecMath<T>::lerp(*this, end, t);
    }

    Vec3<T> clamp(T minVal, T maxVal) const {
        return VecMath<T>::clamp(*this, minVal, maxVal);
    }

    Vec3<T> abs() const {
        return VecMath<T>::abs(*this);
    }
};

template <typename T>
inline T VecMath<T>::dot(const Vec3<T>& a, const Vec3<T>& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

template <typename T>
inline Vec3<T> VecMath<T>::cross(const Vec3<T>& a, const Vec3<T>& b) {
    return Vec3(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    );
}

template <typename T>
inline Vec3<T> VecMath<T>::normalize(const Vec3<T>& v) {
    float magnitude = std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    return Vec3(v.x / magnitude, v.y / magnitude, v.z / magnitude);
}

template <typename T>
inline Vec3<T> VecMath<T>::add(const Vec3<T>& a, const Vec3<T>& b) {
    return Vec3(a.x + b.x, a.y + b.y, a.z + b.z);
}

template <typename T>
inline Vec3<T> VecMath<T>::subtract(const Vec3<T>& a, const Vec3<T>& b) {
    return Vec3<T>(a.x - b.x, a.y - b.y, a.z - b.z);
}

template <typename T>
inline Vec3<T> VecMath<T>::multiply(const Vec3<T>& v, T scalar) {
    return Vec3<T>(v.x * scalar, v.y * scalar, v.z * scalar);
}

template <typename T>
inline Vec3<T> VecMath<T>::multiply(const Vec3<T>& a, const Vec3<T>& b) {
    return Vec3<T>(a.x * b.x, a.y * b.y, a.z * b.z);
}

template <typename T>
inline Vec3<T> VecMath<T>::project(const Vec3<T>& a, const Vec3<T>& b) {
    float dotProduct = dot(a, b);
    float lengthSquared = dot(b, b);

    return multiply(b, dotProduct / lengthSquared);
}

template <typename T>
inline Vec3<T> VecMath<T>::reflect(const Vec3<T>& incident, const Vec3<T>& normal) {
    Vec3<T> normalizedNormal = normalize(normal);
    float dotProduct = 2.0f * dot(incident, normalizedNormal);
    return subtract(incident, multiply(normalizedNormal, dotProduct));
}

template <typename T>
inline Vec3<T> VecMath<T>::lerp(const Vec3<T>& start, const Vec3<T>& end, T t) {
    return Vec3<T>(
        start.x + t * (end.x - start.x),
        start.y + t * (end.y - start.y),
        start.z + t * (end.z - start.z)
    );
}

template <typename T>
inline Vec3<T> VecMath<T>::clamp(const Vec3<T>& v, T minVal, T maxVal) {
    return Vec3<T>(
        std::max(minVal, std::min(v.x, maxVal)),
        std::max(minVal, std::min(v.y, maxVal)),
        std::max(minVal, std::min(v.z, maxVal))
    );
}

template <typename T>
inline Vec3<T> VecMath<T>::abs(const Vec3<T>& v) {
    return Vec3<T>(std::abs(v.x), std::abs(v.y), std::abs(v.z));
}

template <typename T>
class Vec4 {
public:
    T x, y, z, w;

    Vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
    Vec4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}

    T dot(const Vec4<T>& b) const {
        return VecMath<T>::dot(*this, b);
    }

    Vec4<T> normalize() const {
        return VecMath<T>::normalize(*this);
    }

    Vec4<T> add(const Vec4<T>& b) const {
        return VecMath<T>::add(*this, b);
    }

    Vec4<T> subtract(const Vec4<T>& b) const {
        return VecMath<T>::subtract(*this, b);
    }

    Vec4<T> multiply(T scalar) const {
        return VecMath<T>::multiply(*this, scalar);
    }

    Vec4<T> multiply(const Vec4<T>& b) const {
        return VecMath<T>::multiply(*this, b);
    }

    Vec4<T> project(const Vec4<T>& b) const {
        return VecMath<T>::project(*this, b);
    }

    Vec4<T> reflect(const Vec4<T>& normal) const {
        return VecMath<T>::reflect(*this, normal);
    }

    Vec4<T> lerp(const Vec4<T>& end, T t) const {
        return VecMath<T>::lerp(*this, end, t);
    }

    Vec4<T> clamp(T minVal, T maxVal) const {
        return VecMath<T>::clamp(*this, minVal, maxVal);
    }

    Vec4<T> abs() const {
        return VecMath<T>::abs(*this);
    }
};


template <typename T>
inline T VecMath<T>::dot(const Vec4<T>& a, const Vec4<T>& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

template <typename T>
inline Vec4<T> VecMath<T>::normalize(const Vec4<T>& v) {
    float magnitude = std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
    return Vec4<T>(v.x / magnitude, v.y / magnitude, v.z / magnitude, v.w / magnitude);
}

template <typename T>
inline Vec4<T> VecMath<T>::add(const Vec4<T>& a, const Vec4<T>& b) {
    return Vec4<T>(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

template <typename T>
inline Vec4<T> VecMath<T>::subtract(const Vec4<T>& a, const Vec4<T>& b) {
    return Vec4<T>(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

template <typename T>
inline Vec4<T> VecMath<T>::multiply(const Vec4<T>& v, T scalar) {
    return Vec4<T>(v.x * scalar, v.y * scalar, v.z * scalar, v.w * scalar);
}

template <typename T>
inline Vec4<T> VecMath<T>::multiply(const Vec4<T>& a, const Vec4<T>& b) {
    return Vec4<T>(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
}

template <typename T>
inline Vec4<T> VecMath<T>::project(const Vec4<T>& a, const Vec4<T>& b) {
    float dotProduct = dot(a, b);
    float lengthSquared = dot(b, b);

    return multiply(b, dotProduct / lengthSquared);
}

template <typename T>
inline Vec4<T> VecMath<T>::reflect(const Vec4<T>& incident, const Vec4<T>& normal) {
    Vec4<T> normalizedNormal = normalize(normal);
    float dotProduct = 2.0f * dot(incident, normalizedNormal);
    return subtract(incident, multiply(normalizedNormal, dotProduct));
}

template <typename T>
inline Vec4<T> VecMath<T>::lerp(const Vec4<T>& start, const Vec4<T>& end, T t) {
    return Vec4<T>(
        start.x + t * (end.x - start.x),
        start.y + t * (end.y - start.y),
        start.z + t * (end.z - start.z),
        start.w + t * (end.w - start.w)
    );
}

template <typename T>
inline Vec4<T> VecMath<T>::clamp(const Vec4<T>& v, T minVal, T maxVal) {
    return Vec4<T>(
        std::max(minVal, std::min(v.x, maxVal)),
        std::max(minVal, std::min(v.y, maxVal)),
        std::max(minVal, std::min(v.z, maxVal)),
        std::max(minVal, std::min(v.w, maxVal))
    );
}

template <typename T>
inline Vec4<T> VecMath<T>::abs(const Vec4<T>& v) {
    return Vec4<T>(std::abs(v.x), std::abs(v.y), std::abs(v.z), std::abs(v.w));
}

template <typename T>
class Mat4 {
public:
    T m[4][4];

    // Default constructor
    Mat4() {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                m[i][j] = 0;
            }
        }
    }

    // Constructor with initial values
    Mat4(T a11, T a12, T a13, T a14,
        T a21, T a22, T a23, T a24,
        T a31, T a32, T a33, T a34,
        T a41, T a42, T a43, T a44) {
        m[0][0] = a11; m[0][1] = a12; m[0][2] = a13; m[0][3] = a14;
        m[1][0] = a21; m[1][1] = a22; m[1][2] = a23; m[1][3] = a24;
        m[2][0] = a31; m[2][1] = a32; m[2][2] = a33; m[2][3] = a34;
        m[3][0] = a41; m[3][1] = a42; m[3][2] = a43; m[3][3] = a44;
    }

    static Mat4<T> VecMath<T>::transpose(const Mat4<T>&matrix);
    static Mat4<T> VecMath<T>::identity();
    static Mat4<T> VecMath<T>::scale(const Mat4<T>& matrix, T scaleX, T scaleY, T scaleZ);
    static Mat4<T> VecMath<T>::translate(const Mat4<T>& matrix, T translateX, T translateY, T translateZ);

    friend class VecMath<T>;
};

template <typename T>
inline Mat4<T> VecMath<T>::transpose(const Mat4<T>& matrix) {
    Mat4<T> result;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result.m[i][j] = matrix.m[j][i];
        }
    }
    return result;
}

template <typename T>
inline Mat4<T> VecMath<T>::identity() {
    Mat4<T> result;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result.m[i][j] = (i == j) ? static_cast<T>(1) : static_cast<T>(0);
        }
    }
    return result;
}

template <typename T>
inline Mat4<T> VecMath<T>::scale(const Mat4<T>& matrix, T scaleX, T scaleY, T scaleZ) {
    Mat4<T> result = matrix;
    result.m[0][0] *= scaleX;
    result.m[1][1] *= scaleY;
    result.m[2][2] *= scaleZ;
    return result;
}

template <typename T>
inline Mat4<T> VecMath<T>::translate(const Mat4<T>& matrix, T translateX, T translateY, T translateZ) {
    Mat4<T> result = matrix;
    result.m[3][0] += translateX;
    result.m[3][1] += translateY;
    result.m[3][2] += translateZ;
    return result;
}

#endif // VECMATH_IMPL_H