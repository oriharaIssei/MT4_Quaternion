#include "Matrix4x4.h"
#include "Vector3.h"

#include <iostream>

int main(){
	Vector3 from0 = Vector3(1.0f,0.7f,0.5f).Normalize();
	Vector3 to0 = -from0;

	Vector3 from1 = Vector3(-0.6f,0.9f,0.2f).Normalize();
	Vector3 to1 = Vector3(0.4f,0.7f,-0.5f).Normalize();

	Matrix4x4 rotateMatrix[3];
	rotateMatrix[0] = DirectionToDirection(
		Vector3(1.0f,0.0f,0.0f).Normalize(),
		Vector3(-1.0f,0.0f,0.0f).Normalize()
	);
	rotateMatrix[1] = DirectionToDirection(
		from0,to0
	);
	rotateMatrix[2] = DirectionToDirection(
		from1,to1
	);

	for(size_t i = 0; i < 3; i++){
		std::cout << "RotateMatrix" << i << std::endl;
		rotateMatrix[i].Show();
	}
	return 0;
}