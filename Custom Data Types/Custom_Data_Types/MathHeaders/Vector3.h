#pragma once

namespace MathClasses
{
    struct Vector3
    {
        float x, y, z;

        Vector3() : x(0), y(0), z(0) {};
        ~Vector3() {};

        Vector3(float x1, float y1, float z1) : x(x1), y(y1), z(z1) {};

        // Addition of two vectors
        Vector3 operator+(const Vector3& other) const {
            return Vector3(x + other.x, y + other.y, z + other.z);
        }

        // Multiplication of a float and a Vector
        friend Vector3 operator*(float scalar, const Vector3& vec)  {
            return Vector3(scalar * vec.x, scalar * vec.y, scalar * vec.z);
        }

        // Subtraction of two vectors
        Vector3 operator-(const Vector3& other) const {
            return Vector3(x - other.x, y - other.y, z - other.z);
        }

        // Scalar multiplication
        Vector3 operator*(float scalar) const {
            return Vector3(x * scalar, y * scalar, z * scalar);
        }

        // Dot product of two vectors
        float Dot(const Vector3& other) const {
            return x * other.x + y * other.y + z * other.z;
        }

        // Cross product of two vectors
        Vector3 Cross(const Vector3& other) const {
            return Vector3(
                y * other.z - z * other.y,
                z * other.x - x * other.z,
                x * other.y - y * other.x
            );
        }

        // Magnitude of the vector
        float Magnitude() const {
            return std::sqrt(x * x + y * y + z * z);
        }

        // Normalize the vector
        void Normalise() {
            float mag = Magnitude();
            if (mag > 0) {
                x /= mag;
                y /= mag;
                z /= mag;
            }
        }

        // Returns a normalised copy of the Vector
        Vector3 Normalised() const
        {
            Vector3 copy = *this;
            copy.Normalise();

            return copy;
        }

        // Equality operator
        bool operator==(const Vector3& other) const {
            return x == other.x && y == other.y && z == other.z;
        }

        // Inequality operator
        bool operator!=(const Vector3& other) const {
            return !(*this == other);
        }

        // ToString method
        std::string ToString() const {
            return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z);
        }

	};
}