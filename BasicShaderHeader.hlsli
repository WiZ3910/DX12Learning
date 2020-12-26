struct Output {
	float4 svpos : SV_POSITION; // �V�X�e���p���_���W
	float4 normal : NORMAL; //�@���x�N�g��
	float2 uv : TEXCOORD; //UV
};

//�萔�o�b�t�@�[�P
//�}�e���A���p
cbuffer Material : register(b1) {
	float4 diffuse;
	float4 specular;
	float3 ambient;
}