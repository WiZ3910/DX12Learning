#include "BasicShaderHeader.hlsli"

Output BasicVS(float4 pos : POSITION,
	float4 normal : NORMAL,
	float2 uv : TEXCOORD,
			   float2) {
	Output output;
	output.svpos = mul(mat,pos);
	output.uv = uv;
	return output;
}