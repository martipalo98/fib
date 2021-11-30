#version 330 core

out vec4 FragColor;
uniform vec3 colorTronc;

void main() {
    //vec3 color = vec3(0,0,0);

    FragColor = vec4(colorTronc, 1);
}
