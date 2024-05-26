#pragma once
#include <string>
#include <cmath>

namespace MathClasses {
    struct Vector4
    {
        float x, y, z, w;

        // Default constructor
        Vector4() : x(0), y(0), z(0), w(0) {}

        // Constructor with components
        Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

        // Addition of two vectors
        Vector4 operator+(const Vector4& other) const {
            return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
        }

        // Subtraction of two vectors
        Vector4 operator-(const Vector4& other) const {
            return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
        }

        // Scalar multiplication
        Vector4 operator*(float scalar) const {
            return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
        }

        friend Vector4 operator*(float scalar, const Vector4& vec) {
            return Vector4(scalar * vec.x, scalar * vec.y, scalar * vec.z, scalar * vec.w);
        }

        // Dot product of two vectors
        float Dot(const Vector4& other) const {
            return x * other.x + y * other.y + z * other.z + w * other.w;
        }



        // Cross product of two vectors
        // Note: Cross product is typically not defined for 4D vectors in the same way as for 3D.
        // Implementing as if ignoring the fourth component (w), treating them as 3D vectors.
        Vector4 Cross(const Vector4& other) const {
            return Vector4(
                y * other.z - z * other.y,
                z * other.x - x * other.z,
                x * other.y - y * other.x,
                0.0f  // Typically, the w component for a cross product result might be set to 0 or 1 depending on context
            );
        }

        // Magnitude of the vector
        float Magnitude() const {
            return std::sqrt(x * x + y * y + z * z + w * w);
        }

        // Normalize the vector
        void Normalise() {
            float mag = Magnitude();
            if (mag > 0) {
                x /= mag;
                y /= mag;
                z /= mag;
                w /= mag;
            }
        }

        // Returns a normalised copy of the Vector
        Vector4 Normalised() const
        {
            Vector4 copy = *this;
            copy.Normalise();

            return copy;
        }

        bool operator==(const Vector4& other) const {
            const float EPSILON = 0.0001f;
            return (std::fabs(x - other.x) < EPSILON) &&
                (std::fabs(y - other.y) < EPSILON) &&
                (std::fabs(z - other.z) < EPSILON) &&
                (std::fabs(w - other.w) < EPSILON);
        }

        // Inequality operator
        bool operator!=(const Vector4& other) const {
            return !(*this == other);
        }

        // ToString method
        std::string ToString() const {
            return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w);
        }

    };
}