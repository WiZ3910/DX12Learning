#include"BasicShaderHeader.hlsli"
Texture2D<float4> tex:register(t0);//0番スロットに設定されたテクスチャ
SamplerState smp:register(s0);//0番スロットに設定されたサンプラ


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
	//8.3.5 ディフューズの反映
	return max(diffuseB //輝度
		* diffuse * texColor
		* sph.Sample(smp,sphereMapUV) //乗算スフィアマップ
		+ spa.Sample(smp,sphereMapUV) * texColor //加算スフィアマップ
		+ float4(specularB * specular.rgb, 1)
		, float4(ambient * texColor, 1)); //アンビエント
	; //スフィアマップ（乗算）
	//return float4(input.normal.xyz,1);
	//return float4(tex.Sample(smp,input.uv));
}