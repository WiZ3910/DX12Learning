#include"BasicShaderHeader.hlsli"


SamplerState smp:register(s0);//0番スロットに設定されたサンプラ
SamplerState smpToon:register(s1);//1番スロットに設定されたサンプラ（トゥーン用）
Texture2D<float4> tex:register(t0);//0番スロットに設定されたテクスチャ
Texture2D<float4> sph : register(t1);
Texture2D<float4> spa : register(t2);
Texture2D<float4> toon : register(t3);

float4 BasicPS(VertexOutput input) : SV_TARGET{
	float3 light = normalize(float3(1,-1,1));
	//光の反射ベクトル
	float3 refLight = normalize(reflect(light, input.normal.xyz));
	float specularB = pow(saturate(dot(refLight, -input.ray)), specular.a);

	//確認のため、スペキュラのみで着色してみる
	//return float4(specularB * specular.rgb, 1);

	//ディフューズ計算
	float diffuseB = dot(-light, input.normal);
	float brightness = dot(-light, input.normal);
	float2 sphereMapUV = input.vnormal.xy;
	float4 texColor = tex.Sample(smp, input.uv);

	//トゥーンシェーディングやってみる
	float4 toonDif = toon.Sample(smpToon, float2(0, 1.0 - diffuseB));
	return max(saturate(toonDif//輝度(トゥーン)
		* diffuse//ディフューズ色
		* texColor//テクスチャカラー
		* sph.Sample(smp, sphereMapUV))//スフィアマップ(乗算)
		+ saturate(spa.Sample(smp, sphereMapUV) * texColor//スフィアマップ(加算)
			+ float4(specularB * specular.rgb, 1))//スペキュラー
		, float4(texColor * ambient, 1));//アンビエント
	
	//8.3.5 ディフューズの反映
	//return max(diffuseB //輝度
	//	* diffuse * texColor
	//	* sph.Sample(smp,sphereMapUV) //乗算スフィアマップ
	//	+ spa.Sample(smp,sphereMapUV) * texColor //加算スフィアマップ
	//	+ float4(specularB * specular.rgb, 1)
	//	, float4(ambient * texColor, 1)); //アンビエント
	//; 
	//return float4(input.normal.xyz,1);
	//return float4(tex.Sample(smp,input.uv));
}