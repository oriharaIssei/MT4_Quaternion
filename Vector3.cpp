#include "Vector3.h"

#include <iomanip>
#include <iostream>

#include "Quaternion.h"

Vector3 Vector3::RotateVector(const Quaternion& q) const{
	Quaternion r = Quaternion(*this,0.0f);
	r = q * r * q.Conjugation();
	return Vector3(r.x,r.y,r.z);
}

Vector3 Vector3::RotateVector(const Vector3& v,const Quaternion& q){
	Quaternion r = Quaternion(v,0.0f);
	r = q * r * q.Conjugation();
	return Vector3(r.x,r.y,r.z);
}

void Vector3::Show(){
	std::cout << std::fixed << std::setprecision(3) << x << " ";
	std::cout << std::fixed << std::setprecision(3) << y << " ";
	std::cout << std::fixed << std::setprecision(3) << z << " ";
	std::cout << "\n" << std::endl;
}
