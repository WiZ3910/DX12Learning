#pragma once

#ifndef _MATHUTIL_H_INCLUDED__
#define _MATHUTIL_H_INCLUDED__

#include <math.h>

const float kPi = 3.14159265f;
const float k2Pi = kPi * 2.0f;
const float kPiOver2 = kPi / 2.0f;
const float k1OverPi = 1.0f / kPi;
const float k1Over2Pi = 1.0 / k2Pi;

//�K�؂�2�΂̔{���������邱�ƂŊp�x��-��...�΂͈̔͂Ƀ��b�v����
extern float wrapPi(float theta);

//���S�ȋt�O�p�֐�
extern float safeAcos(float x);

//����p�x��sin��cos���v�Z������
//�v���b�g�t�H�[���ɂ���Ă͗����̒l���K�v�Ȃ��Ƃ��킩���Ă���ꍇ�A
//�Q�̒l��ʁX�Ɍv�Z������������v�Z���邱�Ƃ��ł���B
inline void sincos(float* returnSin, float* returnCos, float theta) {
	//�ȗ����̂��߂ɒʏ�̎O�p�֐���p����B
	//���ӂ��ׂ����Ƃ́A�v���b�g�t�H�[���ɂ���Ă͂��ǂ����@��
	//���݂���ꍇ������Ƃ������Ƃł���B
	*returnSin = sin(theta);
	*returnCos = cos(theta);
}

#endif //#ifndef __MATHUTIL_H_INCLUDED