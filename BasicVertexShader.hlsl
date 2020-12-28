#include"BasicShaderHeader.hlsli"
Texture2D<float4> tex:register(t0);//0�ԃX���b�g�ɐݒ肳�ꂽ�e�N�X�`��
SamplerState smp:register(s0);//0�ԃX���b�g�ɐݒ肳�ꂽ�T���v��



VertexOutput BasicVS(float4 pos : POSITION, float4 normal : NORMAL, float2 uv : TEXCOORD) {
	VertexOutput output;//�s�N�Z���V�F�[�_�֓n���l
	pos = mul(world, pos);
	output.svpos = mul(mul(proj, view), pos);//�V�F�[�_�ł͗�D��Ȃ̂Œ���
	output.pos = mul(view, pos);
	normal.w = 0;//�����d�v(���s�ړ������𖳌��ɂ���)
	output.normal = mul(world, normal);//�@���ɂ����[���h�ϊ����s��
	output.vnormal = mul(view, output.normal);
	output.uv = uv;

	return output;
}