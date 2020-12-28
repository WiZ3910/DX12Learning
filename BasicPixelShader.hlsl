#include"BasicShaderHeader.hlsli"


SamplerState smp:register(s0);//0�ԃX���b�g�ɐݒ肳�ꂽ�T���v��
SamplerState smpToon:register(s1);//1�ԃX���b�g�ɐݒ肳�ꂽ�T���v���i�g�D�[���p�j
Texture2D<float4> tex:register(t0);//0�ԃX���b�g�ɐݒ肳�ꂽ�e�N�X�`��
Texture2D<float4> sph : register(t1);
Texture2D<float4> spa : register(t2);
Texture2D<float4> toon : register(t3);

float4 BasicPS(VertexOutput input) : SV_TARGET{
	float3 light = normalize(float3(1,-1,1));
	//���̔��˃x�N�g��
	float3 refLight = normalize(reflect(light, input.normal.xyz));
	float specularB = pow(saturate(dot(refLight, -input.ray)), specular.a);

	//�m�F�̂��߁A�X�y�L�����݂̂Œ��F���Ă݂�
	//return float4(specularB * specular.rgb, 1);

	//�f�B�t���[�Y�v�Z
	float diffuseB = dot(-light, input.normal);
	float brightness = dot(-light, input.normal);
	float2 sphereMapUV = input.vnormal.xy;
	float4 texColor = tex.Sample(smp, input.uv);

	//�g�D�[���V�F�[�f�B���O����Ă݂�
	float4 toonDif = toon.Sample(smpToon, float2(0, 1.0 - diffuseB));
	return max(saturate(toonDif//�P�x(�g�D�[��)
		* diffuse//�f�B�t���[�Y�F
		* texColor//�e�N�X�`���J���[
		* sph.Sample(smp, sphereMapUV))//�X�t�B�A�}�b�v(��Z)
		+ saturate(spa.Sample(smp, sphereMapUV) * texColor//�X�t�B�A�}�b�v(���Z)
			+ float4(specularB * specular.rgb, 1))//�X�y�L�����[
		, float4(texColor * ambient, 1));//�A���r�G���g
	
	//8.3.5 �f�B�t���[�Y�̔��f
	//return max(diffuseB //�P�x
	//	* diffuse * texColor
	//	* sph.Sample(smp,sphereMapUV) //��Z�X�t�B�A�}�b�v
	//	+ spa.Sample(smp,sphereMapUV) * texColor //���Z�X�t�B�A�}�b�v
	//	+ float4(specularB * specular.rgb, 1)
	//	, float4(ambient * texColor, 1)); //�A���r�G���g
	//; 
	//return float4(input.normal.xyz,1);
	//return float4(tex.Sample(smp,input.uv));
}