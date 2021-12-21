#version 330 core

in vec3 vertex;
in vec3 normal;

in vec3  matamb;
in vec3  matdiff;
in vec3  matspec;
in float matshin;

uniform mat4 TG;
uniform mat4 Proj;
uniform mat4 View;

out vec3  fmatamb;
out vec3  fmatdiff;
out vec3  fmatspec;
out float fmatshin;
out vec3  fvertex;
out vec3  fnormal;


void main()
{	

    // Passem les dades al fragment shader
    fmatamb  = matamb;
    fmatdiff = matdiff;
    fmatspec = matspec;
    fmatshin = matshin;
    fvertex = vertex;//vertex/vertex.w; // vertex; // CALCULEU CORRECTAMENT
    //fnormal = normal;//vec3(normal * vec4(normal, 0.0));//normal; // CALCULEU CORRECTAMENT

    fnormal = (inverse(transpose(mat3(View * TG))) * normal);
    fvertex = (View * TG * vec4(vertex, 1.0)).xyz;
    // Passar posicio del vertex a SCO
    // fvertex = (View * TG * vec4(vertex, 1.0)).xyz;
    
    // Passar vector normal a SCO
    //fnormal = (inverse(transpose(mat3(View * TG))) * normal);

    gl_Position = Proj * View * TG * vec4 (vertex, 1.0);
}
