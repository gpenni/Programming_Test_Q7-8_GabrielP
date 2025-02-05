#ifndef BEZIER_H
#define BEZIER_H

#include <vector>
#include <iostream>

class Vector3 {
public:
    float x, y, z;

    Vector3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

    Vector3 operator+(const Vector3& other) const {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    Vector3 operator*(float scalar) const {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    // Re-add the print function
    void print() const {
        std::cout << "(" << x << ", " << y << ", " << z << ")";
    }
};

Vector3 bezierInterpolation(const std::vector<Vector3>& points, float t);
void plotBezierCurve(const std::vector<Vector3>& controlPoints);

#endif