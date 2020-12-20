#pragma once

#ifndef __EULARANGLES_H_INCLUDED__
#define __EULARANGLES_H_INCLUDED__

//�O���Q��
class Quaternion;
class Matrix4x3;
class RotationMatrix;

class EularAngles {
public:
	//�p�u���b�N�ȃf�[�^
	float heading;
	float pitch;
	float bank;

	//�p�u���b�N�ȑ���
	EularAngles() {}

	EularAngles(float h, float p, float b) : heading(h), pitch(p), bank(b) {}
	
	//�P��������i���ׂĂO��ݒ肷��)
	void identity() { pitch = bank = heading = 0.0f; }

	//�����I�C���[�p�̂R�g�����肷��
	void canonize();

	//�l�������I�C���[�`���ɕϊ�����
	//���͂����l�����́A���̖��O�������悤�ɃI�u�W�F�N�g��Ԃ��犵����ԁA
	//�܂��͊�����Ԃ���I�u�W�F�N�g��Ԃւ̉�]�����s������̂Ƃ���
	void fromObjectToInertialQuaternion(const Quaternion &q);
	void fromInertialToObjectQuaternion(const Quaternion& q);

	//���W�ϊ��s����I�C���[�p�`���ɕϊ�����
	//���͂����s��́A���ꂪ�����悤�ɃI�u�W�F�N�g��Ԃ��烏�[���h��ԁA
	//���[���h��Ԃ���I�u�W�F�N�g��Ԃւ̍��W�ϊ������s������̂Ƃ���
	//���̍s��́A���s������̂Ƃ���
	void fromObjectToWorldMatrix(const Matrix4x3 &m);
	void fromWorldToObjectMatrix(const Matrix4x3 &m);

	//��]�s����I�C���[�`���ɕϊ�����
	void fromRotationMatrix(const RotationMatrix& m);
};

extern const EularAngles kEularAnglesIdentity;

#endif // !__EULARANGLES_H_INCLUDED__
