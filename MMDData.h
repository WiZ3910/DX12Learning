#pragma once
#include <DirectXMath.h>
#include <d3d12.h>

#pragma pack(1) //��������P�o�C�g�p�b�L���O�ƂȂ�A�A���C�������g�͔������Ȃ�
struct PMDMaterial
{
	DirectX::XMFLOAT3 diffuse;  //�f�B�t���[�Y //12
	float alpha; //�f�B�t���[�Y�� //4
	float specularity; //�X�y�L�����̋��� //4
	DirectX::XMFLOAT3 specular; //�X�y�L�����F //12
	DirectX::XMFLOAT3 ambient; //�A���r�G���g�F //12
	unsigned char toonIdx; //�g�D�[���ԍ� //1
	unsigned char edgeFlg; //�}�e���A�����Ƃ̗֊s���t���O //1

	//���ӁF�����ɂQ�o�C�g�̃p�f�B���O������ => ���Ȃ��Ȃ���

	unsigned int indicesNum; //���̃}�e���A�������蓖�Ă���C���f�b�N�X��

	char texFilePath[20]; //�e�N�X�`���t�@�C���p�X+�� 
}; //70�o�C�g�̂͂������A�p�f�B���O���������邽��72�o�C�g�ɂȂ� => 70�o�C�g�ɂȂ���
#pragma pack()

