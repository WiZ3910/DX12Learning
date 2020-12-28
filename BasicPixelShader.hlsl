#include"BasicShaderHeader.hlsli"
Texture2D<float4> tex:register(t0);//0�ԃX���b�g�ɐݒ肳�ꂽ�e�N�X�`��
SamplerState smp:register(s0);//0�ԃX���b�g�ɐݒ肳�ꂽ�T���v��


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
	//8.3.5 �f�B�t���[�Y�̔��f
	return max(diffuseB //�P�x
		* diffuse * texColor
		* sph.Sample(smp,sphereMapUV) //��Z�X�t�B�A�}�b�v
		+ spa.Sample(smp,sphereMapUV) * texColor //���Z�X�t�B�A�}�b�v
		+ float4(specularB * specular.rgb, 1)
		, float4(ambient * texColor, 1)); //�A���r�G���g
	; //�X�t�B�A�}�b�v�i��Z�j
	//return float4(input.normal.xyz,1);
	//return float4(tex.Sample(smp,input.uv));
}