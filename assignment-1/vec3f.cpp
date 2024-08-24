#include "vec3f.h"

namespace my{

// Default constructor
Vec3f::Vec3f() {
    for (auto &elem : elements) {
        elem = 0;
    }
}

Vec3f::Vec3f(float a, float b, float c) {
    elements[0] = a;
    elements[1] = b;
    elements[2] = c;
}

// Subscript operator
float &Vec3f::operator[](int index) {
    return elements[index];
}

// Subscript operator for const
float Vec3f::operator[](int index) const {
    return elements[index];
}

// Equality operator
bool Vec3f::operator==(const Vec3f& other) const {
    return elements[0] == other.elements[0] &&
           elements[1] == other.elements[1] &&
           elements[2] == other.elements[2];
}

// Inequality operator
bool Vec3f::operator!=(const Vec3f& other) const {
    return !(*this == other);
}

// += operator
Vec3f& Vec3f::operator+=(const Vec3f &other) {
    elements[0] += other.elements[0];
    elements[1] += other.elements[1];
    elements[2] += other.elements[2];  
    return *this;
}

// Add operator
Vec3f Vec3f::operator+(const Vec3f &other) const {
    Vec3f tmpVec = *this;
    tmpVec += other;
    return tmpVec;
}

// Unary minus operator
Vec3f Vec3f::operator-() const {
    return Vec3f(-elements[0], -elements[1], - elements[2]); 
}

// Dot product 
float dot(const Vec3f& a, const Vec3f& b) {
    return a[0] * b[0] +
           a[1] * b[1] +
           a[2] * b[2];
}

}