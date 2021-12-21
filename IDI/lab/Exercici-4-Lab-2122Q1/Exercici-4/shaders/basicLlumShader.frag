#version 330 core

in vec3  fmatamb;
in vec3  fmatdiff;
in vec3  fmatspec;
in float fmatshin;
in vec3  fvertex;
in vec3  fnormal;

uniform vec3 red;
uniform vec3 green;
uniform vec3 blue;
uniform mat4 posicioMa;
uniform float rotacio;

const vec3 llumAmbient = vec3(0.2, 0.2, 0.2);
const vec3 focusEscena = vec3(8.0, 3.0, 2.0);

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
  vec4 focusMa = (View * TG * posicioMa[3]);
  vec4 focusEscenaa = (View * vec4(focusEscena, 1));

  vec3 L1 = normalize(fnormal - fvertex);
  vec3 L2 = normalize(focusEscenaa.xyz - fvertex);
  vec3 L3 = normalize(focusMa.xyz - fvertex);

  vec3 fcolor = Ambient();
  fcolor += Lambert(fnormal, L1, red);
  fcolor += Lambert(fnormal, L2, green);
  fcolor += Lambert(fnormal, L3, blue);
  fcolor += Phong(fnormal, L1, fvertex, red);
  fcolor += Phong(fnormal, L2, fvertex, green);
  fcolor += Phong(fnormal, L3, fvertex, blue);

  FragColor = vec4(fcolor, 1);
}
