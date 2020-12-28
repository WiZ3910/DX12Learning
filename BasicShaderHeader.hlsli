struct VertexOutput {
	float4 svpos : SV_POSITION; // システム用頂点座標
	float4 pos : POSITION;
	float4 normal : NORMAL; //法線ベクトル
	float4 vnormal : NORMAL1; //ビュー変換後の法線ベクトル
	float2 uv : TEXCOORD; //UV
	float3 ray : VECTOR;
};

// 定数バッファ0
cbuffer SceneData : register(b0) {
	matrix world;//ワールド変換行列
	matrix view;
	matrix proj;
	float3 eye;
};

//定数バッファー１
//マテリアル用
cbuffer Material : register(b1) {
	float4 diffuse;
	float4 specular;
	float3 ambient;
}

Texture2D<float4> sph : register(t1);
Texture2D<float4> spa : register(t2);