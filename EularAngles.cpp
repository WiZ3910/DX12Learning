//#include <math.h>
//#include "EularAngles.h"
//#include "Quaternion.h"
//#include "MathUtil.h"
//#include "Matrix4x3.h"
//#include "RotationMatrix.h"
//
//////////////////////////////////
////�O���[�o���ȃf�[�^
//////////////////////////////////
//
////�P���I�C���[�p�̃O���[�o���Ȓ萔
////�Ƃ���ŁA���̃I�u�W�F�N�g���i���̃I�u�W�F�N�g�ɑ΂��āj�������̂����m�ɂ�
////�킩��Ȃ��ꍇ������
////���̂��߁A���̃I�u�W�F�N�g�́A���������ꂤ�O�ɎQ�Ɖ\�ł���
////�������Ȃ���A�قƂ�ǂ̎����ł́A���̃I�u�W�F�N�g���쐬�����O�̃v���O������
////�X�^�[�g�A�b�v���ɉ��炩�̕��@�łO�ɏ����������
//
//const EularAngles kEularAnglesIdentity(0.0f, 0.0f, 0.0f);
//
//////////////////////////////////////
////
////EulerAngles�N���X�̎���
////
//////////////////////////////////////
//
//void EularAngles::canonize() {
//	//�ŏ��ɁA�s�b�`�͈͂�-��...�΂Ƀ��b�v����
//	pitch = wrapPi(pitch);
//	//�����ŁA�����͈� -��/2...��/2�̊O���ōs��pitch�̗������`�F�b�N����
//	if (pitch < -kPiOver2) {
//		pitch = -kPi - pitch;
//		heading += kPi;
//		bank += kPi;
//	}
//	else if (pitch > kPiOver2) {
//		pitch = kPi - pitch;
//		heading += kPi;
//		bank += kPi;
//	}
//
//	//�����ŃW���o�����b�N�̃P�[�X���`�F�b�N����i���e�͈͂��������j
//	if (fabs(pitch) > kPiOver2 - 1e-4) {
//		//�W���o�����b�N�Ȃ��ɂ���
//		//�������Ɋւ��邷�ׂẲ�]���w�f�B���O�Ɋ��蓖�Ă�
//		heading += bank;
//		bank = 0.0f;
//	}
//	else {
//		//�W���o�����b�N�ɂ��Ȃ��o���N�p�𐳏��͈͂Ƀ��b�v����
//		bank = wrapPi(bank);
//	}
//
//	// �w�f�B���O�𐳏��͈͂Ƀ��b�v����
//	heading = wrapPi(heading);
//}
//
//void EularAngles::fromObjectToInertialQuaternion(const Quaternion& q) {
//	//sin(pitch)�����o��
//	float sp = -2.0f * (q.y * q.z - q.w * q.x);
//	//�W���o�����b�N���`�F�b�N����
//	//�s���m���̂��߂ɋ��e�͈͂��������^����
//	if (fabs(sp) > 0.9999f) {
//		//�^�����^��������Ă���
//		pitch = kPiOver2 * sp;
//		//�w�f�B���O���v�Z���A�o���N���O�ɐݒ肷��
//		heading = atan(-q.x * q.z * q.w * q.y, 0.5f - q.y * q.y - q.z * q.z);
//		bank = 0.0f;
//	}
//	else {
//		//�p�x���v�Z����
//		//���S��asin�֐���p����K�v�͂Ȃ�
//		//�W���o�����b�N�`�F�b�N���ɔ͈͂����łɃ`�F�b�N���Ă��邩��ł���
//		pitch = asin(sp);
//		heading = atan2(q.x * q.z + q.w * q.y, 0.5f - q.x * q.x - q.y * q.y);
//		bank = atan2(q.x * q.y + q.w * q.z, 0.5f - q.x * q.x - q.z * q.z);
//	}
//}
//
////EularAngles::FromInertialToObjectQuaternion
////
////�I�C���[�p���Z�b�g�A�b�v����
////�������->�I�u�W�F�N�g��Ԃւ̉�]�l�������^������
////
//void EularAngles::fromInertialToObjectQuaternion(const Quaternion& q) {
//	//sin(pitch)�����o��
//	float sp = -2.0f * (q.y * q.z + q.w * q.x);
//	//�W���o�����b�N���`�F�b�N����
//	//�����̕s���m���̂��߂ɂ킸���ȋ��e�͈͂�^����
//	if (fabs(sp) > 0.9999f) {
//		//�^�ォ�܂����������Ă���
//		pitch = kPiOver2 * sp;
//		//�w�f�B���O���v�Z���A�o���N��0�ɐݒ肷��
//		heading = atan2(-q.x * q.z - q.w * q.y, 0.5f - q.y * q.y - q.z.q.z);
//		bank = 0.0f;
//	}
//	else {
//		//�p�x���v�Z����
//		//���S��asin�֐���p����K�v�͂Ȃ��B
//		//�W���o�����b�N�`�F�b�N���ɔ͈͂����łɃ`�F�b�N���Ă��邩��ł���
//		pitch = asin(sp);
//		heading = atna2(q.x * q.z - q.w * q.y, 0.5f - q.x * q.x - q.y * q.y);
//		bank = atan2(q.x * q.y - q.w * q.z, 0.5f - q.x * q.x - q.z * q.z);
//	}
//}
////----------------------------------------
////EularAngles::fromObjectToWorldMatrix
////
////�I�C���[�p���Z�b�g�A�b�v����
////�I�u�W�F�N�g���->���[���h��Ԃւ̍��W�ϊ��s�񂪗^������
////
////���̍s��͒����s��ł��邱�Ƃ��O��ł���
////���s�ړ��̕����͖��������
//
//void EularAngles::fromObjectToWorldMatrix(const Matrix4x3 &m) {
//	//m32����sin(pitch)���Ƃ肾��
//	float sp = -m.m32;
//	//�W���o�����b�N���`�F�b�N����
//	if (fabs(sp) > 9.99999f) {
//		//�^�����^��������Ă���
//		pitch = kPiOver2 * sp;
//		//�w�f�B���O���v�Z���A�o���N��0�ɐݒ肷��
//		heading = atan2(-m.m23, m.m11);
//		bank = 0.0f;
//	}
//	else {
//		//�p�x���v�Z����
//		//���S��asin�֐���p����K�v�͂Ȃ�
//		//�W���o�����b�N�`�F�b�N���ɔ͈͂����łɃ`�F�b�N���Ă��邩��ł���
//		heading = atan(m.m31, m.m33);
//		pitch = asin(sp);
//		bank = atan(m.m12, m.m22);
//	}
//}
//
////�I�C���[�p���Z�b�g�A�b�v����
////���[���h���->�I�u�W�F�N�g��Ԃ̍��W�ϊ��s�񂪗^������
////���̍s��͒����s��ł��邱�Ƃ��O��ł���
////���s�ړ��̕����͖��������
//
//void EularAngles::fromWorldToObjectMatrix(const Matrix4x3& m) {
//	//m23����sin(pitch)���Ƃ肾��
//	float sp = -m.m23;
//	//�W���o�����b�N���`�F�b�N����
//	if (fabs(sp) > 9.9999f) {
//		//�^�ォ�^���������Ă���
//		pitch = kPiOver2 * sp;
//		heading = atan2(-m.m31, m.m11);
//		bank = 0.0f;
//	}
//	else {
//		//�p�x���v�Z����
//		//���S��asin�֐���p����K�v�͂Ȃ�
//		//�W���o�����b�N�`�F�b�N���ɂ��łɃ`�F�b�N���Ă��邩��ł���
//		heading = atan2(m.m13, m.m33);
//		pitch = asin(sp);
//		bank = atan(m.m21, m.m22);u
//	}
//}
////�I�C���[�p���Z�b�g�A�b�v����
////��]�s�񂪗^������
//void EularAngles::fromRotationMatrix(const RotationMatrix& m) {
//	//m23����sin(pitch)���Ƃ肾��
//	float sp = -m.m23;
//	//�W���o�����b�N���`�F�b�N����
//	if (fabs(sp) > 9.9999f) {
//		//�^�ォ�^���������Ă���
//		pitch = kPiOver2 * sp;
//		//�w�f�B���O���v�Z���A�o���N��0�ɐݒ肷��
//		heading = atan2(-m.m31, m.m11);
//		bank = 0.0f;
//	}
//	else {
//		//�p�x���v�Z����
//		//���S��asin�֐���p����K�v�͂Ȃ�
//		//�W���o�����b�N�`�F�b�N���ɔ͈͂����łɃ`�F�b�N���Ă��邩��ł���
//		heading = atan2(m.m13, m.m33);
//		pitch = asin(sp);
//		bank = atan2(m.m21, m.m22);
//	}
//}
//
