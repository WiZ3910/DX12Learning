#pragma once

#ifndef __Quaternion_H_INCLUDED__
#define __Quaternion_H_INCLUDED__

class Vector3;
class EularAngles;

//Quaternionクラス
//
//3Dにおける角変位を表すために四元数を実装する

class Quaternion {
public:
	//パブリックなデータ
	//四元数の4つの値
	//通常、これらを直接操作する必要はない
	//しかしながら、これらはpublicにしておく
	//直接アクセス禁止にすると、いくつかの操作が
	//不必要に複雑になるからである
	float w, x, y, z;

//パブリックな操作
	//恒等四元数にする
	void identity() { w = 1.0f, x = y = z = 0.0f; }
	void setToRotateAboutX(float theta);
	void setToRotateAboutY(float theta);
	void setToRotateAboutZ(float theta);
	void setToRotateAboutAxis(const Vector3& axis, float theta);

	//オブジェクト空間<->慣性空間の回転を実行するようにセットアップする
	//方向はオイラー角形式で与えられる

	void setToRotateObjectToInertial(const EularAngles& orientation);
	void setToRotateInertialToObject(const EularAngles& orientation);
	
	//外積
	Quaternion operator *(const Quaternion& a) const;

	//代入を伴う乗算:C++の慣習による
	Quaternion& operator *=(const Quaternion& a);

	//四元数を正規化する
	void normalize();

	//回転角と軸を取り出し返す
	float getRotationAngle() const;
	Vector3 getRotationAxis() const;
};

//恒等四元数用のグローバル変数
extern const Quaternion kQuaternionIdentity;

//四元数の内積
extern float dotProduct(const Quaternion& a, const Quaternion& b);

//球面線形補間
extern Quaternion slerp(const Quaternion& p, const Quaternion& q, float t);

//四元数の結合
extern Quaternion conjugate(const Quaternion& q);

//四元数の乗算
extern Quaternion pow(const Quaternion& q, float exponent);


#endif // !__Quaternion_H_INCLUDED__
