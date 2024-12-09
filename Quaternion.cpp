#include "Quaternion.h"

#include <cmath>
#include <iomanip>
#include <iostream>

Quaternion Quaternion::operator*(const Quaternion& q)const{
	return {
		w * q.x + x * q.w + y * q.z - z * q.y, // x'
		w * q.y + y * q.w + z * q.x - x * q.z, // y'
		w * q.z + z * q.w + x * q.y - y * q.x, // z'
		w * q.w - x * q.x - y * q.y - z * q.z  // w'
	};
}

Quaternion Quaternion::operator/(float scalar)const{
	return Quaternion(
		this->x / scalar,
		this->y / scalar,
		this->z / scalar,
		this->w / scalar
	);
}

Quaternion Quaternion::Inverse(const Quaternion& q){
	float normSq = q.normSq();// ノルムの二乗
	if(normSq == 0.0f){
		// ノルムが0の場合、逆元は存在しない
		return {0.0f,0.0f,0.0f,0.0f}; // エラー処理としてゼロ四元数を返す
	}
	Quaternion conjugate = q.Conjugation();
	return conjugate / normSq; // 共役をノルムの二乗で割る
}

Quaternion Quaternion::inverse() const{
	float normSq = this->normSq();// ノルムの二乗
	if(normSq == 0.0f){
		// ノルムが0の場合、逆元は存在しない
		return {0.0f,0.0f,0.0f,0.0f}; // エラー処理としてゼロ四元数を返す
	}
	Quaternion conjugate = this->Conjugation();
	return conjugate / normSq; // 共役をノルムの二乗で割る
}

float Quaternion::Norm(Quaternion q){
	return sqrtf(q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z);
}

float Quaternion::norm() const{
	return sqrtf(this->w * this->w + this->x * this->x + this->y * this->y + this->z * this->z);
}

float Quaternion::NormSq(Quaternion q){
	return q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z;
}

float Quaternion::normSq() const{
	return this->w * this->w + this->x * this->x + this->y * this->y + this->z * this->z;
}

Quaternion Quaternion::Normalize(Quaternion q){
	float norm = q.norm();
	if(norm == 0.0f){
		return {0.0f,0.0f,0.0f,0.0f};
	}
	return q / norm;
}

Quaternion Quaternion::normalize() const{
	float norm = this->norm();
	if(norm == 0.0f){
		return {0.0f,0.0f,0.0f,0.0f};
	}
	return *this / norm;
}

void Quaternion::Show(){
	std::cout << std::fixed << std::setprecision(3) << x << " ";
	std::cout << std::fixed << std::setprecision(3) << y << " ";
	std::cout << std::fixed << std::setprecision(3) << z << " ";
	std::cout << std::fixed << std::setprecision(3) << w << " ";
	std::cout << "\n" << std::endl;
}