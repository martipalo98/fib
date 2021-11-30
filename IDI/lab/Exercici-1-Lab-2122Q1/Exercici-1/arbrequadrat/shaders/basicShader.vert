#version 330 core

in vec3 vertex;
//in vec4 colors;
//out vec4 colorsfora;
uniform float val;
uniform mat4 TG;

void main()  {
    gl_Position = TG * vec4 (vertex, 1.0);
    //colorsfora = colors;
}
