#pragma once

#include <cmath>

struct Quaternion;
struct Vector3{
	float x,y,z;

	Vector3(const float& x,const float& y,const float& z):x(x),y(y),z(z){};
	Vector3(const float* v):x(v[0]),y(v[1]),z(v[2]){};
	Vector3():x(0),y(0),z(0){};

	///
	///	演算子
	///
	Vector3& operator=(const Vector3& another){
		this->x = another.x;
		this->y = another.y;
		this->z = another.z;
		return *this;
	}
	bool operator==(const Vector3& v)const{
		return x == v.x && y == v.y && z == v.z;
	}
	Vector3 operator+(const Vector3& another)const{
		return Vector3(
			this->x + another.x,
			this->y + another.y,
			this->z + another.z
		);
	}
	Vector3& operator+=(const Vector3& another){
		this->x += another.x;
		this->y += another.y;
		this->z += another.z;
		return *this;
	}

	Vector3 operator-(const Vector3& another)const{
		return Vector3(
			this->x - another.x,
			this->y - another.y,
			this->z - another.z
		);
	}
	Vector3 operator-()const{
		return Vector3(
			-this->x,
			-this->y,
			-this->z
		);
	}

	Vector3& operator-=(const Vector3& another){
		this->x -= another.x;
		this->y -= another.y;
		this->z -= another.z;
		return *this;
	}

	Vector3 operator*(const float& scalar)const{
		return Vector3(
			this->x * scalar,
			this->y * scalar,
			this->z * scalar
		);
	}
	Vector3& operator*=(const float& scalar){
		this->x *= scalar;
		this->y *= scalar;
		this->z *= scalar;
		return *this;
	}

	float dot(const Vector3& another)const{
		return this->x * another.x + this->y * another.y + this->z * another.z;
	}
	float length()const{
		return std::sqrtf(dot(*this));
	}

	Vector3 cross(const Vector3& other)const{
		return {
			y * other.z - z * other.y,
			z * other.x - x * other.z,
			x * other.y - y * other.x
		};
	}

	Vector3 Normalize()const{
		float len = this->length();
		if(len == 0.0f){
			return *this;
		}
		return Vector3(
			this->x / len,
			this->y / len,
			this->z / len
		);
	}

	Vector3 RotateVector(const Quaternion& q)const;
	static Vector3 RotateVector(const Vector3& v,const Quaternion& q);

	void Show();
};

