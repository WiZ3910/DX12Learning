#include"BasicType.hlsli"
#include"BasicShaderHeader.hlsli"
Texture2D<float4> tex:register(t0);//0番スロットに設定されたテクスチャ
SamplerState smp:register(s0);//0番スロットに設定されたサンプラ


float4 BasicPS(BasicType input) : SV_TARGET{
	float3 light = normalize(float3(1,-1,1));
	float brightness = dot(-light, input.normal);
	//8.3.5 ディフューズの反映
	return float4(brightness, brightness, brightness, 1) * diffuse;
	//return float4(input.normal.xyz,1);
	//return float4(tex.Sample(smp,input.uv));
}