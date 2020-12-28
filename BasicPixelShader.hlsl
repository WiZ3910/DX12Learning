#include"BasicShaderHeader.hlsli"
Texture2D<float4> tex:register(t0);//0番スロットに設定されたテクスチャ
SamplerState smp:register(s0);//0番スロットに設定されたサンプラ


float4 BasicPS(VertexOutput input) : SV_TARGET{
	float3 light = normalize(float3(1,-1,1));
	float brightness = dot(-light, input.normal);
	float2 sphereMapUV = input.vnormal.xy;
	float4 color = tex.Sample(smp, input.uv);
	//8.3.5 ディフューズの反映
	return float4(brightness, brightness, brightness, 1)
		* diffuse
		* color
		* sph.Sample(smp, sphereMapUV)
		+ spa.Sample(smp, sphereMapUV)
		+float4(color * ambient, 1)
	; //スフィアマップ（乗算）
	//return float4(input.normal.xyz,1);
	//return float4(tex.Sample(smp,input.uv));
}