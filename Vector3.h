#pragma once

class Vector3 {
public:
	float x, y, z;
	
	Vector3(){}

	//コピーコンストラクタ
	Vector3(const Vector3& a) : x(a.x), y(a.y), z(a.z) {}

	//３つの値で作成する
	Vector3(float nx, float ny, float nz) : x(nx), y(ny), z(nz) {}

	//標準的なオブジェクトの保守
	Vector3& operator = (const Vector3& a) {
		x = a.x; y = a.y; z = a.z;
		return *this;
	}
	//ひとしさのチェック
	bool operator ==(const Vector3& a) const {
		return x == a.x && y == a.y;
	}

	bool operator !=(const Vector3& a) const {
		return x != a.x || y != a.y || z != a.z;
	}
	
	void zero() { x = y = z = 0.0f; }

	Vector3 operator -() const { return Vector3(-x, -y, -z); }
	Vector3 operator +(const Vector3& a) const {
		return Vector3(x + a.x, y + a.y, z + a.z);
	}
	Vector3 operator -(const Vector3& a) const {
		return Vector3(x - a.x, y - a.y, z - a.z);
	}
	//スカラーによる乗算と減算
	Vector3 operator *(float a) const {
		return Vector3(x * a, y * a, z * a);
	}
	Vector3 operator /(float a) const {
		float oneOverA = 1.0f / a;
		return Vector3(x * oneOverA, y * oneOverA, z * oneOverA);
	}
	//Cの表記法に準拠するための組み合わせ代入演算
	Vector3& operator +=(const Vector3& a) {
		x += a.x; y += a.y; z += a.z;
	}



};