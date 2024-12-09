#pragma once

#include "Vector3.h"

struct Quaternion;

struct Matrix4x4{
	float m[4][4];

	///
	///	演算子
	///
	float* operator[](int index){ return m[index]; }
	const float* operator[](int index) const{ return m[index]; }

	Matrix4x4 operator+(const Matrix4x4& another) const;
	Matrix4x4 operator-(const Matrix4x4& another) const;
	Matrix4x4 operator*(const Matrix4x4& another) const;
	Matrix4x4 operator*(const float& scalar) const;

	Matrix4x4* operator*=(const Matrix4x4& another);

	Matrix4x4 Transpose()const;

	void Show();
};

namespace MakeMatrix{
	Matrix4x4 Identity();

	Matrix4x4 Translate(const Vector3& vec);
	Matrix4x4 Scale(const Vector3& vec);
	Matrix4x4 RotateX(const float& radian);
	Matrix4x4 RotateY(const float& radian);
	Matrix4x4 RotateZ(const float& radian);
	Matrix4x4 RotateXYZ(const Vector3& radian);
	Matrix4x4 RotateXYZ(const Matrix4x4& x,const Matrix4x4& y,const Matrix4x4& z);

	Matrix4x4 RotateQuaternion(const Quaternion& q);

	Matrix4x4 RotateAxisAngle(const Vector3& axis,float angle);

	Matrix4x4 Affine(const Vector3& scale,const Vector3& rotate,const Vector3& translate);

	Matrix4x4 PerspectiveFov(const float& fovY,const float& aspectRatio,const float& nearClip,const float& farClip);
	Matrix4x4 Orthographic(const float& left,const float& top,const float& right,const float& bottom,const float& nearClip,const float& farClip);
	Matrix4x4 ViewPort(const float& left,const float& top,const float& width,const float& height,const float& minDepth,const float& maxDepth);
}

Vector3 TransformVector(const Vector3& vec,const Matrix4x4& matrix);
Vector3 TransformNormal(const Vector3& v,const Matrix4x4& m);

Matrix4x4 DirectionToDirection(const Vector3& from,const Vector3& to);