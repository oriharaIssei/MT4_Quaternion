#include "Matrix4x4.h"
#include "Quaternion.h"
#include "Vector3.h"

#include <iostream>

int main(){
	Quaternion q1 = {2.0f,3.0f,4.0f,1.0f};
	Quaternion q2 = {1.0f,3.0f,5.0f,2.0f};
	Quaternion identity = Quaternion::Identity();
	Quaternion conj = Quaternion::Conjugation(q1);
	Quaternion inv = Quaternion::Inverse(q1);
	Quaternion normal = Quaternion::Normalize(q1);
	Quaternion mul1 = q1 * q2;
	Quaternion mul2 = q2 * q1;

	identity.Show();
	conj.Show();
	inv.Show();
	normal.Show();
	mul1.Show();
	mul2.Show();

	return 0;
}