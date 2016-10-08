// classic Phong equation
#version 410

in vec4 vPosition;
in vec4 vNormal;
out vec4 fragColor;

uniform vec3 Ka;
uniform vec3 Ia;
uniform vec3 Kd;
uniform vec3 Id;
uniform vec3 Ks;
uniform vec3 Is;

uniform vec3 lightDirection;
uniform vec3 cameraPosition;
uniform float specularPower;

void main()
{
	vec3 Lm = normalize(lightDirection);
	vec3 N = normalize(vNormal.xyz);
	vec3 Rm = 2 * dot(N,Lm) * N - Lm;
	vec3 V = normalize(cameraPosition - vPosition.xyz);
	vec3 red = vec3(250,0,0);
	vec3 green = vec3(0,250,0);
	vec3 blue = vec3(0,0,250);

	float a = dot(N,vec3(0,1.f,0));
	vec3 hemisphere = .5f * mix(blue,green,a) + .5f;
	float specularTerm = pow(max(0.0f,dot(Rm,V)),specularPower);
	float lambertTerm = max(0.0f,dot(N,Lm));

	vec3 Ambient = (Ia * .01f) * (Ka) * hemisphere;
	vec3 Diffuse = Kd * lambertTerm * Id;
	vec3 Specular = Is * Ks * specularTerm;

	fragColor = vec4(Diffuse + Ambient + Specular,1);
	//fragColor = vec4(Ambient,1);
	//fragColor = vec4(Diffuse,1);
	//fragColor = vec4(Specular,1);
	//fragColor = vec4(Ambient + Diffuse,1);
	//fragColor = vec4(Ambient + Specular,1);
	//fragColor = vec4(Diffuse + Specular,1);
}