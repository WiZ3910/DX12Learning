#pragma once

#ifndef __Quaternion_H_INCLUDED__
#define __Quaternion_H_INCLUDED__

class Vector3;
class EularAngles;

//Quaternion�N���X
//
//3D�ɂ�����p�ψʂ�\�����߂Ɏl��������������

class Quaternion {
public:
	//�p�u���b�N�ȃf�[�^
	//�l������4�̒l
	//�ʏ�A�����𒼐ڑ��삷��K�v�͂Ȃ�
	//�������Ȃ���A������public�ɂ��Ă���
	//���ڃA�N�Z�X�֎~�ɂ���ƁA�������̑��삪
	//�s�K�v�ɕ��G�ɂȂ邩��ł���
	float w, x, y, z;

//�p�u���b�N�ȑ���
	//�P���l�����ɂ���
	void identity() { w = 1.0f, x = y = z = 0.0f; }
	void setToRotateAboutX(float theta);
	void setToRotateAboutY(float theta);
	void setToRotateAboutZ(float theta);
	void setToRotateAboutAxis(const Vector3& axis, float theta);

	//�I�u�W�F�N�g���<->������Ԃ̉�]�����s����悤�ɃZ�b�g�A�b�v����
	//�����̓I�C���[�p�`���ŗ^������

	void setToRotateObjectToInertial(const EularAngles& orientation);
	void setToRotateInertialToObject(const EularAngles& orientation);
	
	//�O��
	Quaternion operator *(const Quaternion& a) const;

	//����𔺂���Z:C++�̊��K�ɂ��
	Quaternion& operator *=(const Quaternion& a);

	//�l�����𐳋K������
	void normalize();

	//��]�p�Ǝ������o���Ԃ�
	float getRotationAngle() const;
	Vector3 getRotationAxis() const;
};

//�P���l�����p�̃O���[�o���ϐ�
extern const Quaternion kQuaternionIdentity;

//�l�����̓���
extern float dotProduct(const Quaternion& a, const Quaternion& b);

//���ʐ��`���
extern Quaternion slerp(const Quaternion& p, const Quaternion& q, float t);

//�l�����̌���
extern Quaternion conjugate(const Quaternion& q);

//�l�����̏�Z
extern Quaternion pow(const Quaternion& q, float exponent);


#endif // !__Quaternion_H_INCLUDED__
