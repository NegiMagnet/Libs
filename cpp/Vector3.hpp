#pragma once

#include <cmath>

//--------------------
// 3次元ベクトル
//--------------------

class Vector3 {
public:

	//--------------------
	// value
	//--------------------

	float x, y, z;

	//--------------------
	// constructor
	//--------------------

	Vector3(){}
	Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z){}
	Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z){}

	//--------------------
	// operator
	//--------------------

	// u = v
	Vector3& operator=(const Vector3 &v) {
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}

	// u + v
	Vector3 operator+(const Vector3 &v) {
		return Vector3(x+v.x, y+v.y, z+v.z);
	}

	// u - v
	Vector3 operator-(const Vector3 &v) {
		return Vector3(x-v.x, y-v.y, z-v.z);
	}

	// -u
	Vector3 operator-() {
		return Vector3(-x, -y, -z);
	}

	// u * k
	Vector3 operator*(const float k) {
		return Vector3(x*k, y*k, z*k);
	}

	// u / k
	Vector3 operator/(const float k) {
		float inv = 1.0f / k;
		return Vector3(x*inv, y*inv, z*inv);
	}

	// u == v
	bool operator==(const Vector3 &v) const {
		return (x==v.x && y==v.y && z==v.z);
	}

	// u != v
	bool operator!=(const Vector3 &v) const {
		return !(x==v.x && y==v.y && z==v.z);
	}

	//--------------------
	// utils
	//--------------------

	// return normalized vector
	static Vector3 normalize(const Vector3 &v) {
		float sq = v.x*v.x + v.y*v.y + v.z*v.z;
		if(sq > 0.0f) {
			sq = 1.0f / std::sqrt(sq);
			return Vector3(v.x*sq, v.y*sq, v.z*sq);
		} else {
			return Vector3(0,0,0);
		}
	}

	// magnitude
	static float magnitude(const Vector3 &v) {
		return std::sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
	}

	// dot
	static float dot(const Vector3& u, const Vector3& v) {
		return u.x*v.x + u.y*v.y + u.z*v.z;
	}

	// cross
	static Vector3 cross(const Vector3& u, const Vector3& v) {
		return Vector3(u.y*v.z - u.z*v.y, u.z*v.x - u.x*v.z, u.x*v.y - u.y*v.x);
	}

	// distance
	static float distance(const Vector3& u, const Vector3& v) {
		float dx = u.x - v.x;
		float dy = u.y - v.y;
		float dz = u.z - v.z;
		return std::sqrt(dx*dx + dy*dy + dz*dz);
	}

};

inline Vector3 operator*(float k, const Vector3 &v) {
	return Vector3(k*v.x, k*v.y, k*v.z);
}
