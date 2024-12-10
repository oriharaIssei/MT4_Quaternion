#include "Matrix4x4.h"
#include "Quaternion.h"
#include "Vector3.h"

#include <iostream>

int main(){
	Quaternion rotate0 = Quaternion::RotateAxisAngle({0.71f,0.71f,0.0f},0.3f);
	Quaternion rotate1 = Quaternion::RotateAxisAngle({0.71f,0.0f,0.71f},3.141592f);

	Quaternion interpolate0 = Slerp(rotate0,rotate1,0.0f);
	interpolate0.Show();
	Quaternion interpolate1 = Slerp(rotate0,rotate1,0.3f);
	interpolate1.Show();
	Quaternion interpolate2 = Slerp(rotate0,rotate1,0.5f);
	interpolate2.Show();
	Quaternion interpolate3 = Slerp(rotate0,rotate1,0.7f);
	interpolate3.Show();
	Quaternion interpolate4 = Slerp(rotate0,rotate1,1.0f);
	interpolate4.Show();

	return 0;
}