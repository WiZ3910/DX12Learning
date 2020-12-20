#pragma once

#ifndef _MATHUTIL_H_INCLUDED__
#define _MATHUTIL_H_INCLUDED__

#include <math.h>

const float kPi = 3.14159265f;
const float k2Pi = kPi * 2.0f;
const float kPiOver2 = kPi / 2.0f;
const float k1OverPi = 1.0f / kPi;
const float k1Over2Pi = 1.0 / k2Pi;

//適切に2πの倍数を加えることで角度を-π...πの範囲にラップする
extern float wrapPi(float theta);

//安全な逆三角関数
extern float safeAcos(float x);

//ある角度のsinとcosを計算すうｒ
//プラットフォームによっては両方の値が必要なことがわかっている場合、
//２つの値を別々に計算するよりも早く計算することができる。
inline void sincos(float* returnSin, float* returnCos, float theta) {
	//簡略化のために通常の三角関数を用いる。
	//注意すべきことは、プラットフォームによってはより良い方法が
	//存在する場合があるということである。
	*returnSin = sin(theta);
	*returnCos = cos(theta);
}

#endif //#ifndef __MATHUTIL_H_INCLUDED