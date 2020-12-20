//#include <math.h>
//#include "EularAngles.h"
//#include "Quaternion.h"
//#include "MathUtil.h"
//#include "Matrix4x3.h"
//#include "RotationMatrix.h"
//
//////////////////////////////////
////グローバルなデータ
//////////////////////////////////
//
////恒等オイラー角のグローバルな定数
////ところで、このオブジェクトが（他のオブジェクトに対して）いつ作られるのか正確には
////わからない場合がある
////このため、このオブジェクトは、初期化されう前に参照可能である
////しかしながら、ほとんどの実装では、他のオブジェクトが作成される前のプログラムの
////スタートアップ時に何らかの方法で０に初期化される
//
//const EularAngles kEularAnglesIdentity(0.0f, 0.0f, 0.0f);
//
//////////////////////////////////////
////
////EulerAnglesクラスの実装
////
//////////////////////////////////////
//
//void EularAngles::canonize() {
//	//最初に、ピッチ範囲を-π...πにラップする
//	pitch = wrapPi(pitch);
//	//ここで、正準範囲 -π/2...π/2の外側で行列pitchの裏側をチェックする
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
//	//ここでジンバルロックのケースをチェックする（許容範囲を少し持つ）
//	if (fabs(pitch) > kPiOver2 - 1e-4) {
//		//ジンバルロックないにいる
//		//垂直軸に関するすべての回転をヘディングに割り当てる
//		heading += bank;
//		bank = 0.0f;
//	}
//	else {
//		//ジンバルロックにいないバンク角を正準範囲にラップする
//		bank = wrapPi(bank);
//	}
//
//	// ヘディングを正準範囲にラップする
//	heading = wrapPi(heading);
//}
//
//void EularAngles::fromObjectToInertialQuaternion(const Quaternion& q) {
//	//sin(pitch)を取り出す
//	float sp = -2.0f * (q.y * q.z - q.w * q.x);
//	//ジンバルロックをチェックする
//	//不正確さのために許容範囲をすこし与える
//	if (fabs(sp) > 0.9999f) {
//		//真下か真上を向いている
//		pitch = kPiOver2 * sp;
//		//ヘディングを計算し、バンクを０に設定する
//		heading = atan(-q.x * q.z * q.w * q.y, 0.5f - q.y * q.y - q.z * q.z);
//		bank = 0.0f;
//	}
//	else {
//		//角度を計算する
//		//安全なasin関数を用いる必要はない
//		//ジンバルロックチェック時に範囲をすでにチェックしているからである
//		pitch = asin(sp);
//		heading = atan2(q.x * q.z + q.w * q.y, 0.5f - q.x * q.x - q.y * q.y);
//		bank = atan2(q.x * q.y + q.w * q.z, 0.5f - q.x * q.x - q.z * q.z);
//	}
//}
//
////EularAngles::FromInertialToObjectQuaternion
////
////オイラー角をセットアップする
////慣性空間->オブジェクト空間への回転四元数が与えられる
////
//void EularAngles::fromInertialToObjectQuaternion(const Quaternion& q) {
//	//sin(pitch)を取り出す
//	float sp = -2.0f * (q.y * q.z + q.w * q.x);
//	//ジンバルロックをチェックする
//	//数字の不正確さのためにわずかな許容範囲を与える
//	if (fabs(sp) > 0.9999f) {
//		//真上かましたを向いている
//		pitch = kPiOver2 * sp;
//		//ヘディングを計算し、バンクを0に設定する
//		heading = atan2(-q.x * q.z - q.w * q.y, 0.5f - q.y * q.y - q.z.q.z);
//		bank = 0.0f;
//	}
//	else {
//		//角度を計算する
//		//安全なasin関数を用いる必要はない。
//		//ジンバルロックチェック時に範囲をすでにチェックしているからである
//		pitch = asin(sp);
//		heading = atna2(q.x * q.z - q.w * q.y, 0.5f - q.x * q.x - q.y * q.y);
//		bank = atan2(q.x * q.y - q.w * q.z, 0.5f - q.x * q.x - q.z * q.z);
//	}
//}
////----------------------------------------
////EularAngles::fromObjectToWorldMatrix
////
////オイラー角をセットアップする
////オブジェクト空間->ワールド空間への座標変換行列が与えられる
////
////この行列は直交行列であることが前提である
////平行移動の部分は無視される
//
//void EularAngles::fromObjectToWorldMatrix(const Matrix4x3 &m) {
//	//m32からsin(pitch)をとりだす
//	float sp = -m.m32;
//	//ジンバルロックをチェックする
//	if (fabs(sp) > 9.99999f) {
//		//真下か真上を向いている
//		pitch = kPiOver2 * sp;
//		//ヘディングを計算し、バンクを0に設定する
//		heading = atan2(-m.m23, m.m11);
//		bank = 0.0f;
//	}
//	else {
//		//角度を計算する
//		//安全なasin関数を用いる必要はない
//		//ジンバルロックチェック時に範囲をすでにチェックしているからである
//		heading = atan(m.m31, m.m33);
//		pitch = asin(sp);
//		bank = atan(m.m12, m.m22);
//	}
//}
//
////オイラー角をセットアップする
////ワールド空間->オブジェクト空間の座標変換行列が与えられる
////この行列は直交行列であることが前提である
////並行移動の部分は無視される
//
//void EularAngles::fromWorldToObjectMatrix(const Matrix4x3& m) {
//	//m23からsin(pitch)をとりだす
//	float sp = -m.m23;
//	//ジンバルロックをチェックする
//	if (fabs(sp) > 9.9999f) {
//		//真上か真下を向いている
//		pitch = kPiOver2 * sp;
//		heading = atan2(-m.m31, m.m11);
//		bank = 0.0f;
//	}
//	else {
//		//角度を計算する
//		//安全なasin関数を用いる必要はない
//		//ジンバルロックチェック時にすでにチェックしているからである
//		heading = atan2(m.m13, m.m33);
//		pitch = asin(sp);
//		bank = atan(m.m21, m.m22);u
//	}
//}
////オイラー角をセットアップする
////回転行列が与えられる
//void EularAngles::fromRotationMatrix(const RotationMatrix& m) {
//	//m23からsin(pitch)をとりだす
//	float sp = -m.m23;
//	//ジンバルロックをチェックする
//	if (fabs(sp) > 9.9999f) {
//		//真上か真下をもいている
//		pitch = kPiOver2 * sp;
//		//ヘディングを計算し、バンクを0に設定する
//		heading = atan2(-m.m31, m.m11);
//		bank = 0.0f;
//	}
//	else {
//		//角度を計算する
//		//安全なasin関数を用いる必要はない
//		//ジンバルロックチェック時に範囲をすでにチェックしているからである
//		heading = atan2(m.m13, m.m33);
//		pitch = asin(sp);
//		bank = atan2(m.m21, m.m22);
//	}
//}
//
