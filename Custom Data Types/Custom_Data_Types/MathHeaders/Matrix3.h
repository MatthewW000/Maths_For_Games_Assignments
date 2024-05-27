#pragma once
#include "Vector3.h"
#include <string>
#include <cmath>

namespace MathClasses {
	struct Matrix3 {
		float m1, m4, m7; // First column
		float m2, m5, m8; // Second column
		float m3, m6, m9; // Third column

		Matrix3() : 
			m1(0), m2(0), m3(0), 
			m4(0), m5(0), m6(0), 
			m7(0), m8(0), m9(0) 
		{}

		Matrix3(float m1, float m2, float m3, 
			float m4, float m5, float m6, 
			float m7, float m8, float m9)
			: 
			m1(m1), m2(m2), m3(m3), 
			m4(m4), m5(m5), m6(m6), 
			m7(m7), m8(m8), m9(m9) 
		{}


		// Constructor from array
		explicit Matrix3(const float arr[])
			: 
			m1(arr[0]), m4(arr[3]), m7(arr[6]),
			m2(arr[1]), m5(arr[4]), m8(arr[7]),
			m3(arr[2]), m6(arr[5]), m9(arr[8]) {}

		// Operator overloads for matrix-matrix multiplication
		Matrix3 operator*(const Matrix3& other) const {
			return Matrix3(
				m1 * other.m1 + m4 * other.m2 + m7 * other.m3,
				m2 * other.m1 + m5 * other.m2 + m8 * other.m3,
				m3 * other.m1 + m6 * other.m2 + m9 * other.m3,
				m1 * other.m4 + m4 * other.m5 + m7 * other.m6,
				m2 * other.m4 + m5 * other.m5 + m8 * other.m6,
				m3 * other.m4 + m6 * other.m5 + m9 * other.m6,
				m1 * other.m7 + m4 * other.m8 + m7 * other.m9,
				m2 * other.m7 + m5 * other.m8 + m8 * other.m9,
				m3 * other.m7 + m6 * other.m8 + m9 * other.m9
			);
		}

		// Operator overload for matrix-vector multiplication
		Vector3 operator*(const Vector3& vec) const {
			return Vector3(
				m1 * vec.x + m4 * vec.y + m7 * vec.z,
				m2 * vec.x + m5 * vec.y + m8 * vec.z,
				m3 * vec.x + m6 * vec.y + m9 * vec.z
			);
		}

		// Make an identity matrix
		static Matrix3 MakeIdentity() {
			return { 1, 0, 0, 0, 1, 0, 0, 0, 1 };
		}

		// Transpose the matrix
		Matrix3 Transposed() const {
			return Matrix3(
				m1, m4, m7,
				m2, m5, m8,
				m3, m6, m9
			);
		}

		// Rotate around X-axis
		static Matrix3 MakeRotateX(float radians) {
			return Matrix3(
				1, 0, 0,
				0, cos(radians), sin(radians),
				0, -sin(radians), cos(radians)
			);
		}

		// Rotate around Y-axis
		static Matrix3 MakeRotateY(float radians) {
			return Matrix3(
				cos(radians), 0, -sin(radians),
				0, 1, 0,
				sin(radians), 0, cos(radians)
			);
		}

		// Rotate around Z-axis
		static Matrix3 MakeRotateZ(float radians) {
			return Matrix3(
				cos(radians), -sin(radians), 0,
				sin(radians), cos(radians), 0,
				0, 0, 1
			);
		}

		// Euler rotations
		static Matrix3 MakeEuler(float pitch, float yaw, float roll) {
			Matrix3 x = MakeRotateX(pitch);
			Matrix3 y = MakeRotateY(yaw);
			Matrix3 z = MakeRotateZ(roll);
			return (z * y * x);
		}

		static Matrix3 MakeEuler(const Vector3& v) {
			return MakeEuler(v.x, v.y, v.z);
		}

		// Scaling matrices
		static Matrix3 MakeScale(float xScale, float yScale, float zScale) {
			return Matrix3(xScale, 0.0f, 0.0f,
				0.0f, yScale, 0.0f,
				0.0f, 0.0f, zScale);
		}

		static Matrix3 MakeScale(float xScale, float yScale) {
			return Matrix3(
				xScale, 0.0f, 0.0f,
				0.0f, yScale, 0.0f,
				0.0f, 0.0f, 1.0f);
		}

		static Matrix3 MakeScale(const Vector3& v) {
			return MakeScale(v.x, v.y, v.z);
		}


		static Matrix3 MakeRotation(float radians) {
			float c = cos(radians);
			float s = sin(radians);
			return Matrix3(c, s, 0, -s, c, 0, 0, 0, 1);
		}

		void Set(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9) {
			this->m1 = m1; this->m2 = m2; this->m3 = m3;
			this->m4 = m4; this->m5 = m5; this->m6 = m6;
			this->m7 = m7; this->m8 = m8; this->m9 = m9;
		}

		void Set(const Matrix3& m) {
			this->m1 = m.m1; this->m2 = m.m2; this->m3 = m.m3;
			this->m4 = m.m4; this->m5 = m.m5; this->m6 = m.m6;
			this->m7 = m.m7; this->m8 = m.m8; this->m9 = m.m9;
		}

		static Matrix3 MakeTranslation(float x, float y) {
			return Matrix3(
				1, 0, 0, 
				0, 1, 0, 
				x, y, 1);
		}


		// Translation matrix from floats with z component
		static Matrix3 MakeTranslation(float tx, float ty, float tz) {
			return Matrix3(
				1.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f,
				tx, ty, tz
			);
		}

		// Translation matrix from a Vector3
		static Matrix3 MakeTranslation(const Vector3& v) {
			return Matrix3(
				1.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f,
				v.x, v.y, v.z
			);
		}

		// Get translation vector
		Vector3 GetTranslation() const {
			return Vector3(m7, m8, 0.0f);
		}

		void SetTranslation(float x, float y) {
			m7 = x;
			m8 = y;
		}

		void Translate(float x, float y) {
			m7 += x;
			m8 += y;
		}

		bool operator==(const Matrix3& other) const {
			const float EPSILON = 0.0001f;
			return (std::fabs(m1 - other.m1) < EPSILON) &&
				(std::fabs(m2 - other.m2) < EPSILON) &&
				(std::fabs(m3 - other.m3) < EPSILON) &&
				(std::fabs(m4 - other.m4) < EPSILON) &&
				(std::fabs(m5 - other.m5) < EPSILON) &&
				(std::fabs(m6 - other.m6) < EPSILON) &&
				(std::fabs(m7 - other.m7) < EPSILON) &&
				(std::fabs(m8 - other.m8) < EPSILON) &&
				(std::fabs(m9 - other.m9) < EPSILON);
		}

		void RotateZ(float radians) {
			*this = *this * MakeRotation(radians);
		}

		void Scale(float x, float y) {
			*this = *this * MakeScale(x, y);
		}

		// Inequality operator
		bool operator!=(const Matrix3& other) const {
			return !(*this == other);
		}

		// ToString method
		std::string ToString() const {
			return std::to_string(m1) + ", " + std::to_string(m2) + ", " + std::to_string(m3) + ", " +
				std::to_string(m4) + ", " + std::to_string(m5) + ", " + std::to_string(m6) + ", " +
				std::to_string(m7) + ", " + std::to_string(m8) + ", " + std::to_string(m9);
		}
	};
}
