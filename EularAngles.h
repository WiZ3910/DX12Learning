#pragma once

#ifndef __EULARANGLES_H_INCLUDED__
#define __EULARANGLES_H_INCLUDED__

//前方参照
class Quaternion;
class Matrix4x3;
class RotationMatrix;

class EularAngles {
public:
	//パブリックなデータ
	float heading;
	float pitch;
	float bank;

	//パブリックな操作
	EularAngles() {}

	EularAngles(float h, float p, float b) : heading(h), pitch(p), bank(b) {}
	
	//恒等化する（すべて０を設定する)
	void identity() { pitch = bank = heading = 0.0f; }

	//正準オイラー角の３つ組を決定する
	void canonize();

	//四元数をオイラー形式に変換する
	//入力される四元数は、その名前が示すようにオブジェクト空間から慣性空間、
	//または慣性空間からオブジェクト空間への回転を実行するものとする
	void fromObjectToInertialQuaternion(const Quaternion &q);
	void fromInertialToObjectQuaternion(const Quaternion& q);

	//座標変換行列をオイラー角形式に変換する
	//入力される行列は、それが示すようにオブジェクト空間からワールド空間、
	//ワールド空間からオブジェクト空間への座標変換を実行するものとする
	//この行列は、直行するものとする
	void fromObjectToWorldMatrix(const Matrix4x3 &m);
	void fromWorldToObjectMatrix(const Matrix4x3 &m);

	//回転行列をオイラー形式に変換する
	void fromRotationMatrix(const RotationMatrix& m);
};

extern const EularAngles kEularAnglesIdentity;

#endif // !__EULARANGLES_H_INCLUDED__
