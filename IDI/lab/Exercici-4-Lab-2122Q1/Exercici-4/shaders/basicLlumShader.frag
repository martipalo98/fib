#version 330 core

in vec3  fmatamb;
in vec3  fmatdiff;
in vec3  fmatspec;
in float fmatshin;
in vec3  fvertex;
in vec3  fnormal;

const vec3 red  = vec3(0.9, 0.2, 0.2);
const vec3 green= vec3(0.2, 0.9, 0.2);
const vec3 blue = vec3(0.2, 0.2, 0.9);

const vec3 llumAmbient = vec3(0.8, 0.2, 0.9);
const vec3 focusCamera = vec3(8.0, 3.0, 2.0);
const vec3 focusEscena = vec3(5.0, 3.0, 5.0);

uniform mat4 TG;
uniform mat4 Proj;
uniform mat4 View;

out vec4 FragColor;


vec3 Ambient() {
  return llumAmbient*fmatamb;
}

vec3 Lambert (vec3 NormSCO, vec3 L, vec3 colorFocus)
{
  // Fixeu-vos que SOLS es retorna el terme de Lambert!
  // S'assumeix que els vectors que es reben com a paràmetres estan normalitzats
  vec3 colorRes = vec3(0);
  if (dot (L, NormSCO) > 0)
    colorRes = colorFocus * fmatdiff * dot (L, NormSCO);
  return (colorRes);
}

vec3 Phong (vec3 NormSCO, vec3 L, vec3 vertSCO, vec3 colorFocus)
{
  // Fixeu-vos que SOLS es retorna el terme especular!
  // Assumim que els vectors estan normalitzats
  vec3 colorRes = vec3 (0);
  // Si la llum ve de darrera o el material és mate no fem res
  if ((dot(NormSCO,L) < 0) || (fmatshin == 0))
    return colorRes;  // no hi ha component especular

  vec3 R = reflect(-L, NormSCO); // equival a: 2.0*dot(NormSCO,L)*NormSCO - L;
  vec3 V = normalize(-vertSCO); // perquè la càmera està a (0,0,0) en SCO

  if (dot(R, V) < 0)
    return colorRes;  // no hi ha component especular

  float shine = pow(max(0.0, dot(R, V)), fmatshin);
  return (colorRes + fmatspec * colorFocus * shine);
}

void main()
{ 

//NOU
   mat3 NormalMatrix = transpose(inverse(mat3(View*TG)));//inverse(transpose(mat3(View * TG)));
  // vec3 NormSCO = normalize(NormalMatrix * fnormal);
  // vec3 VertSCO = View * TG * vec4(fvertex, 1);
  vec3 normal= normalize(NormalMatrix * fnormal);

  vec3 L = normalize(normal - fvertex.xyz); // Direccio llum  
  vec3 NM = normalize(fnormal); 
  
  vec3 color = Phong(NM, L, vec4(vertexF, 1));
  FragColor = vec4(color, 1);

  //focus càmera
  //vec3 L         = NormalMatrix * VertSCO;
  //vec3 Lxyz      = normalize(focus);
                      // mat3 NormalMatrix = inverse(transpose(mat3(View * TG)));
                      // vec3 L = normalize(NormalMatrix - fvertex.xyz);
                      // vec3 color = Phong(fnormal, L, fvertex, red);
                      // FragColor = vec4(color, 1);


  // Dixar posicio del focus de llum en SCA
  //vec3 L = normalize(fnormal - fvertex.xyz); // Direccio llum
  //vec3 L = normalize(vec3(10, 10, 10) - vec3(5, 0, 5));
  //vec3 NM = normalize(fnormal); 
  
  //vec3 color = Phong(NM, L, fvertex, vec3(0.9, 0.2, 0.2));
  //FragColor = vec4(fcolor,1);
  
    //float ambientStrength = 0.1;
    //vec3 ambient = ambientStrength * lightColor;

    //vec3 result = Ambient * glm::vec3(0.5, 0.5, 0.5);
    //FragColor = vec4(result, 1.0);
    //FragColor = vec4(fmatdiff, 1);
}
