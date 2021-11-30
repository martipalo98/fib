/*#version 330 core

out vec4 FragColor;
in vec4 colorsfora;
uniform float val;

void main() {
    vec3 color = vec3(0.6, 0.38, 0.25);
    int num = int(gl_FragCoord.y)/10;
    FragColor = vec4(color, 1);
    if(num%2 == 0) {
        FragColor = vec4(0.4, 0.8, 0.2, 1.);
    }else discard;
}
*/
#version 330 core

out vec4 FragColor;
uniform vec3 colorTronc;

void main() {
    vec3 color = vec3(0,0.5,0);
    if(gl_FragCoord.y < 240.) FragColor = vec4(colorTronc, 1);
    else FragColor = vec4(color, 1);
}
