uniform vec2 frag_LightOrigin;
uniform vec4 frag_LightColor;
uniform float frag_LightRange;

void main()
{

	vec2 baseDistance =  gl_FragCoord.xy;

	vec2 distance=frag_LightOrigin - baseDistance;
    float linear_distance = length(distance);
    float attenuation=1.0;
    if(linear_distance>0.0)
        attenuation = pow(0.99,linear_distance);
    if(attenuation<0.0)
        attenuation = 0.0;
    gl_FragColor=(frag_LightColor*attenuation) + vec4(0.2,0.2,0.4,1.0);




}
