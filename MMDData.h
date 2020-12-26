#pragma once
#include <DirectXMath.h>
#include <d3d12.h>

#pragma pack(1) //ここから１バイトパッキングとなり、アラインメントは発生しない
struct PMDMaterial
{
	DirectX::XMFLOAT3 diffuse;  //ディフューズ //12
	float alpha; //ディフューズα //4
	float specularity; //スペキュラの強さ //4
	DirectX::XMFLOAT3 specular; //スペキュラ色 //12
	DirectX::XMFLOAT3 ambient; //アンビエント色 //12
	unsigned char toonIdx; //トゥーン番号 //1
	unsigned char edgeFlg; //マテリアルごとの輪郭線フラグ //1

	//注意：ここに２バイトのパディングがある => しなくなった

	unsigned int indicesNum; //このマテリアルが割り当てられるインデックス数

	char texFilePath[20]; //テクスチャファイルパス+α 
}; //70バイトのはずだが、パディングが発生するため72バイトになる => 70バイトになった
#pragma pack()

