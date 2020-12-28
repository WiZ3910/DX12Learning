struct VertexOutput {
	float4 svpos : SV_POSITION; // �V�X�e���p���_���W
	float4 pos : POSITION;
	float4 normal : NORMAL; //�@���x�N�g��
	float4 vnormal : NORMAL1; //�r���[�ϊ���̖@���x�N�g��
	float2 uv : TEXCOORD; //UV
	float3 ray : VECTOR;
};

// �萔�o�b�t�@0
cbuffer SceneData : register(b0) {
	matrix world;//���[���h�ϊ��s��
	matrix view;
	matrix proj;
	float3 eye;
};

//�萔�o�b�t�@�[�P
//�}�e���A���p
cbuffer Material : register(b1) {
	float4 diffuse;
	float4 specular;
	float3 ambient;
}

Texture2D<float4> sph : register(t1);
Texture2D<float4> spa : register(t2);