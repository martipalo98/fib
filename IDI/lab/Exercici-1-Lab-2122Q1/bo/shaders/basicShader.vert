#version 330 core

uniform vec3 colorTronc;
in vec3 vertex;

void main()  {
    gl_Position = vec4 (vertex, 1.0);
}
