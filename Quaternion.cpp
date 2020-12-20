#include "Quaternion.h"
#include <math.h>
#include <assert.h>
#include "vector3.h"
#include "EularAngles.h"

const Quaternion kQuaternionOIdentity = {
	1.0f, 0.0f, 0.0f, 0.0f
};

/////////////////////////////////
//
// Quaternionクラスのメンバ
//
/////////////////////////////////

void Quaternion::setToRotateAboutX(float theta) {
	//半分の角度を計算する
	float thetaOver2 = theta * .5f;

	//値を設定する
	w = cos(thetaOver2);
	x = sin(thetaOver2);
	y = 0;
	z = 0;
}

void Quaternion::setToRotateAboutY(float theta) {
	//半分の角度を計算する
	float thetaOver2 = theta * .5f;

	//値を設定する
	w = cos(thetaOver2);
	x = 0;
	y = sin(thetaOver2);
	z = 0;
}

void Quaternion::setToRotateAboutZ(float theta) {
	//半分の角度を計算する
	float thetaOver2 = theta * .5f;

	//値を設定する
	w = cos(thetaOver2);
	x = 0;
	y = 0;
	z = sin(thetaOver2);
}

void Quaternion::setToRotateAboutAxis(const Vector3& axis, float theta) {
	//回転角は正規化されている必要がある
	//assert(fabs(vectorMag(axis) - 1.0f) < .01f);

	//半分の角度とそのsinを計算する
	float thetaOver2 = theta * .5f;
	float sinThetaOver2 = sin(thetaOver2);

	//値を設定する
	w = cos(thetaOver2);
	x = axis.x * sinThetaOver2;
	y = axis.y * sinThetaOver2;
	z = axis.z * sinThetaOver2;
}
