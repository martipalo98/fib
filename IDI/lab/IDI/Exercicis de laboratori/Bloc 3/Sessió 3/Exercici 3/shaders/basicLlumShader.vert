# (c) FIBerHub, https://fiberhub.tk
#version 330 core

in vec3 vertex;
in vec3 normal;

in vec3 matamb;
in vec3 matdiff;
in vec3 matspec;
in float matshin;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 TG;

out vec4 vertexSCO;
out vec3 NormSCO;

out vec3 matambF;
out vec3 matdiffF;
out vec3 matspecF;
out float matshinF;

void main()
{
    mat3 nMatrix = inverse(transpose(mat3(view * TG)));
    NormSCO = normalize(nMatrix * normal);
    vertexSCO = view * TG * vec4(vertex, 1.0);

    matambF = matamb;
    matdiffF = matdiff;
	matspecF = matspec;
	matshinF = matshin;

    gl_Position = proj * view * TG * vec4 (vertex, 1.0);
}
