#include <math.h>
#include "MathUtil.h"

float wrapPi(float theta) {
	theta += kPi;
	theta -= floor(theta * k1Over2Pi) * k2Pi;
	theta -= kPi;
	return theta;
}

extern float safeAcos(float x) {
	//制限条件をチェックする
	if (x < -1.0f)
		return kPi;
	if (x > 1.0f)
		return 0.0f;

	//値が範囲内 --- 標準のC関数を用いる
	return acos(x);
}