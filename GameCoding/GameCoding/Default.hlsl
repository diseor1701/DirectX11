struct VS_INPUT
{
    float4 position : POSITION;
    //float4 color : COLOR;
    float2 uv : TEXCOORD;
};

struct VS_OUTPUT
{
    float4 position : SV_POSITION;
    //float4 color : COLOR; 
    float2 uv : TEXCOORD;
};

cbuffer TransformData : register(b0)
{
    row_major matrix matWrold;
    row_major matrix matView;
    row_major matrix matProjection;
}

// IA - VS - RS - PS - OM
VS_OUTPUT VS(VS_INPUT input)
{
    VS_OUTPUT output;
    
    // WVP
    float4 position = mul(input.position, matWrold); // W
    position = mul(position, matView); // V
    position = mul(position, matProjection); // P
    
    output.position = position;
    output.uv = input.uv;
    
    return output;
}

// t0 레지스터 에다가 텍스쳐0 이라는 아이를 등록 할 것이다라고 예고
Texture2D texture0 : register(t0);
SamplerState sampler0 : register(s0);

float4 PS(VS_OUTPUT input) : SV_Target
{
    float4 color = texture0.Sample(sampler0, input.uv);
    
    return color;
}
