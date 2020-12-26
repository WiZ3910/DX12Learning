#include"BasicType.hlsli"
#include"BasicShaderHeader.hlsli"
Texture2D<float4> tex:register(t0);//0�ԃX���b�g�ɐݒ肳�ꂽ�e�N�X�`��
SamplerState smp:register(s0);//0�ԃX���b�g�ɐݒ肳�ꂽ�T���v��


float4 BasicPS(BasicType input) : SV_TARGET{
	float3 light = normalize(float3(1,-1,1));
	float brightness = dot(-light, input.normal);
	//8.3.5 �f�B�t���[�Y�̔��f
	return float4(brightness, brightness, brightness, 1) * diffuse;
	//return float4(input.normal.xyz,1);
	//return float4(tex.Sample(smp,input.uv));
}