#version 330 core

in vec3 vertex;
//in vec4 colors;
//out vec4 colorsfora;
uniform float val;

void main()  {
    gl_Position = vec4 (vertex*val, 1.0);
    //colorsfora = colors;
}
