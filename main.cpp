#include "Matrix4x4.h"
#include "Vector3.h"

void main(){
	Vector3 axis = Vector3(1.0f,1.0f,1.0f).Normalize();
	float angle = 0.44f;
	Matrix4x4 rotateMatrix = MakeMatrix::RotateAxisAngle(axis,angle);

	rotateMatrix.Show();
}