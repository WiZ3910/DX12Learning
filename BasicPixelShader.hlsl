#include"BasicShaderHeader.hlsli"
Texture2D<float4> tex:register(t0);//0�ԃX���b�g�ɐݒ肳�ꂽ�e�N�X�`��
SamplerState smp:register(s0);//0�ԃX���b�g�ɐݒ肳�ꂽ�T���v��


float4 BasicPS(VertexOutput input) : SV_TARGET{
	float3 light = normalize(float3(1,-1,1));
	float brightness = dot(-light, input.normal);
	float2 sphereMapUV = input.vnormal.xy;
	float4 color = tex.Sample(smp, input.uv);
	//8.3.5 �f�B�t���[�Y�̔��f
	return float4(brightness, brightness, brightness, 1)
		* diffuse
		* color
		* sph.Sample(smp, sphereMapUV)
		+ spa.Sample(smp, sphereMapUV)
		+float4(color * ambient, 1)
	; //�X�t�B�A�}�b�v�i��Z�j
	//return float4(input.normal.xyz,1);
	//return float4(tex.Sample(smp,input.uv));
}