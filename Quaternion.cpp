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
// Quaternion�N���X�̃����o
//
/////////////////////////////////

void Quaternion::setToRotateAboutX(float theta) {
	//�����̊p�x���v�Z����
	float thetaOver2 = theta * .5f;

	//�l��ݒ肷��
	w = cos(thetaOver2);
	x = sin(thetaOver2);
	y = 0;
	z = 0;
}

void Quaternion::setToRotateAboutY(float theta) {
	//�����̊p�x���v�Z����
	float thetaOver2 = theta * .5f;

	//�l��ݒ肷��
	w = cos(thetaOver2);
	x = 0;
	y = sin(thetaOver2);
	z = 0;
}

void Quaternion::setToRotateAboutZ(float theta) {
	//�����̊p�x���v�Z����
	float thetaOver2 = theta * .5f;

	//�l��ݒ肷��
	w = cos(thetaOver2);
	x = 0;
	y = 0;
	z = sin(thetaOver2);
}

void Quaternion::setToRotateAboutAxis(const Vector3& axis, float theta) {
	//��]�p�͐��K������Ă���K�v������
	//assert(fabs(vectorMag(axis) - 1.0f) < .01f);

	//�����̊p�x�Ƃ���sin���v�Z����
	float thetaOver2 = theta * .5f;
	float sinThetaOver2 = sin(thetaOver2);

	//�l��ݒ肷��
	w = cos(thetaOver2);
	x = axis.x * sinThetaOver2;
	y = axis.y * sinThetaOver2;
	z = axis.z * sinThetaOver2;
}
