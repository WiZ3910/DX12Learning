struct Output {
	float4 svpos : SV_POSITION; // システム用頂点座標
	float4 normal : NORMAL; //法線ベクトル
	float2 uv : TEXCOORD; //UV
};

//定数バッファー１
//マテリアル用
cbuffer Material : register(b1) {
	float4 diffuse;
	float4 specular;
	float3 ambient;
}