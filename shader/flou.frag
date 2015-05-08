uniform sampler2D frag_Texture;
uniform vec2 frag_rectLT;
uniform vec2 frag_rectRB;

void main(){

    vec2 screenSize = textureSize2D(frag_Texture,0).xy;
    vec2 position = gl_FragCoord.xy;
    vec2 texturePosition = position/screenSize;
    if(   position.x<frag_rectLT.x
       || position.y < frag_rectLT.y
       || position.x > frag_rectRB.x
       || position.y > frag_rectRB.y )
        gl_FragColor = texture(frag_Texture, texturePosition);
    else{
        vec3 color=vec3(0.0,0.0,0.0);
        int cmpt = 0;
        int prec = 11;
        for(int i=0;i<prec;i++){
            for(int j=0;j<prec;j++){
                color+= texture(frag_Texture, vec2(position.x-prec/2+i,position.y-prec/2+j)/screenSize).xyz;
                cmpt +=1;
            }
        }
        color = color/cmpt;
        gl_FragColor = vec4(color,1.0);
    }


}
