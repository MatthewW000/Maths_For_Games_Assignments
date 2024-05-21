#pragma once
#include "Vector4.h"
#include <string>
#include <cmath>

namespace MathClasses {
    struct Matrix4 {
        float m1, m5, m9, m13;  // First column
        float m2, m6, m10, m14; // Second column
        float m3, m7, m11, m15; // Third column
        float m4, m8, m12, m16; // Fourth column

        // Default constructor
        Matrix4() :
            m1(0), m5(0), m9(0), m13(0),
            m2(0), m6(0), m10(0), m14(0),
            m3(0), m7(0), m11(0), m15(0),
            m4(0), m8(0), m12(0), m16(0)
        {}

        // Destructor
        ~Matrix4() {}

        // Parameterized constructor for individual floats
        Matrix4(float a1, float a5, float a9, float a13,
            float a2, float a6, float a10, float a14,
            float a3, float a7, float a11, float a15,
            float a4, float a8, float a12, float a16)
            : m1(a1), m2(a5), m3(a9), m4(a13),  // First column
            m5(a2), m6(a6), m7(a10), m8(a14),  // Second column
            m9(a3), m10(a7), m11(a11), m12(a15),  // Third column
            m13(a4), m14(a8), m15(a12), m16(a16) // Fourth column
        {}

        // Constructor from array
        explicit Matrix4(const float arr[])
            :
            m1(arr[0]), m2(arr[1]), m3(arr[2]), m4(arr[3]),
            m5(arr[4]), m6(arr[5]), m7(arr[6]), m8(arr[7]),
            m9(arr[8]), m10(arr[9]), m11(arr[10]), m12(arr[11]),
            m13(arr[12]), m14(arr[13]), m15(arr[14]), m16(arr[15])
        {}

        // Operator overload for matrix-matrix multiplication
        Matrix4 operator*(const Matrix4& other) const {
            return Matrix4(
                // First column
                m1 * other.m1 + m5 * other.m2 + m9 * other.m3 + m13 * other.m4,
                m1 * other.m5 + m5 * other.m6 + m9 * other.m7 + m13 * other.m8,
                m1 * other.m9 + m5 * other.m10 + m9 * other.m11 + m13 * other.m12,
                m1 * other.m13 + m5 * other.m14 + m9 * other.m15 + m13 * other.m16,

                // Second column
                m2 * other.m1 + m6 * other.m2 + m10 * other.m3 + m14 * other.m4,
                m2 * other.m5 + m6 * other.m6 + m10 * other.m7 + m14 * other.m8,
                m2 * other.m9 + m6 * other.m10 + m10 * other.m11 + m14 * other.m12,
                m2 * other.m13 + m6 * other.m14 + m10 * other.m15 + m14 * other.m16,

                // Third column
                m3 * other.m1 + m7 * other.m2 + m11 * other.m3 + m15 * other.m4,
                m3 * other.m5 + m7 * other.m6 + m11 * other.m7 + m15 * other.m8,
                m3 * other.m9 + m7 * other.m10 + m11 * other.m11 + m15 * other.m12,
                m3 * other.m13 + m7 * other.m14 + m11 * other.m15 + m15 * other.m16,

                // Fourth column
                m4 * other.m1 + m8 * other.m2 + m12 * other.m3 + m16 * other.m4,
                m4 * other.m5 + m8 * other.m6 + m12 * other.m7 + m16 * other.m8,
                m4 * other.m9 + m8 * other.m10 + m12 * other.m11 + m16 * other.m12,
                m4 * other.m13 + m8 * other.m14 + m12 * other.m15 + m16 * other.m16
            );
        }

        // Operator overload for matrix-vector multiplication
        Vector4 operator*(const Vector4& vec) const {
            return Vector4(
                m1 * vec.x + m5 * vec.y + m9 * vec.z + m13 * vec.w,
                m2 * vec.x + m6 * vec.y + m10 * vec.z + m14 * vec.w,
                m3 * vec.x + m7 * vec.y + m11 * vec.z + m15 * vec.w,
                m4 * vec.x + m8 * vec.y + m12 * vec.z + m16 * vec.w
            );
        }

        // Function to create an identity matrix
        static Matrix4 MakeIdentity() {
            return { 1, 0, 0, 0,
                     0, 1, 0, 0,
                     0, 0, 1, 0,
                     0, 0, 0, 1 };
        }

        // Translation matrix from floats
        static Matrix4 MakeTranslation(float tx, float ty, float tz) {
            return Matrix4(
                1.0f, 0.0f, 0.0f, 0.0f,
                0.0f, 1.0f, 0.0f, 0.0f,
                0.0f, 0.0f, 1.0f, 0.0f,
                tx, ty, tz, 1.0f
            );
        }

        // Translation matrix from a Vector4
        static Matrix4 MakeTranslation(const Vector4& v) {
            return Matrix4(
                1.0f, 0.0f, 0.0f, 0.0f,
                0.0f, 1.0f, 0.0f, 0.0f,
                0.0f, 0.0f, 1.0f, 0.0f,
                v.x, v.y, v.z, v.w
            );
        }

        // Rotate around X-axis
        static Matrix4 MakeRotateX(float radians) {
            return Matrix4(
                1, 0, 0, 0,
                0, cos(radians), sin(radians), 0,
                0, -sin(radians), cos(radians), 0,
                0, 0, 0, 1
            );
        }

        // Rotate around Y-axis
        static Matrix4 MakeRotateY(float radians) {
            return Matrix4(
                cos(radians), 0, -sin(radians), 0,
                0, 1, 0, 0,
                sin(radians), 0, cos(radians), 0,
                0, 0, 0, 1
            );
        }

        // Rotate around Z-axis
        static Matrix4 MakeRotateZ(float radians) {
            return Matrix4(
                cos(radians), sin(radians), 0, 0,
                -sin(radians), cos(radians), 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1
            );
        }

        // Euler rotations
        static Matrix4 MakeEuler(float pitch, float yaw, float roll) {
            Matrix4 x = MakeRotateX(pitch);
            Matrix4 y = MakeRotateY(yaw);
            Matrix4 z = MakeRotateZ(roll);
            return z * y * x;
        }

        static Matrix4 MakeEuler(const Vector4& v) {
            return MakeEuler(v.x, v.y, v.z);
        }

        // Equality operator
        bool operator==(const Matrix4& other) const {
            return m1 == other.m1 && m2 == other.m2 && m3 == other.m3 && m4 == other.m4 &&
                m5 == other.m5 && m6 == other.m6 && m7 == other.m7 && m8 == other.m8 &&
                m9 == other.m9 && m10 == other.m10 && m11 == other.m11 && m12 == other.m12 &&
                m13 == other.m13 && m14 == other.m14 && m15 == other.m15 && m16 == other.m16;
        }

        // Inequality operator
        bool operator!=(const Matrix4& other) const {
            return !(*this == other);
        }

        // ToString method
        std::string ToString() const {
            return std::to_string(m1) + ", " + std::to_string(m2) + ", " + std::to_string(m3) + ", " + std::to_string(m4) + ", " +
                std::to_string(m5) + ", " + std::to_string(m6) + ", " + std::to_string(m7) + ", " + std::to_string(m8) + ", " +
                std::to_string(m9) + ", " + std::to_string(m10) + ", " + std::to_string(m11) + ", " + std::to_string(m12) + ", " +
                std::to_string(m13) + ", " + std::to_string(m14) + ", " + std::to_string(m15) + ", " + std::to_string(m16);
        }
    };
}
