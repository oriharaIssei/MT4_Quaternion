#include "Matrix4x4.h"
#include "Quaternion.h"
#include "Vector3.h"

#include <iostream>

int main(){
	Quaternion rotate = Quaternion::RotateAxisAngle(
		Vector3(1.0f,0.4f,-0.2f).Normalize(),0.45f
	);
	rotate.Show();

	Matrix4x4 rotateMat = MakeMatrix::RotateQuaternion(rotate);
	rotateMat.Show();

	Vector3 pointY = {2.1f,-0.9f,1.3f};
	Vector3 rotateByQuaternion = Vector3::RotateVector(pointY,rotate);
	rotateByQuaternion.Show();
	Vector3 rotateByMatrix = TransformVector(pointY,rotateMat);
	rotateByMatrix.Show();

	return 0;
}