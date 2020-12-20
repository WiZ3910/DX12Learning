#pragma once

class Vector3 {
public:
	float x, y, z;
	
	Vector3(){}

	//�R�s�[�R���X�g���N�^
	Vector3(const Vector3& a) : x(a.x), y(a.y), z(a.z) {}

	//�R�̒l�ō쐬����
	Vector3(float nx, float ny, float nz) : x(nx), y(ny), z(nz) {}

	//�W���I�ȃI�u�W�F�N�g�̕ێ�
	Vector3& operator = (const Vector3& a) {
		x = a.x; y = a.y; z = a.z;
		return *this;
	}
	//�ЂƂ����̃`�F�b�N
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
	//�X�J���[�ɂ���Z�ƌ��Z
	Vector3 operator *(float a) const {
		return Vector3(x * a, y * a, z * a);
	}
	Vector3 operator /(float a) const {
		float oneOverA = 1.0f / a;
		return Vector3(x * oneOverA, y * oneOverA, z * oneOverA);
	}
	//C�̕\�L�@�ɏ������邽�߂̑g�ݍ��킹������Z
	Vector3& operator +=(const Vector3& a) {
		x += a.x; y += a.y; z += a.z;
	}



};