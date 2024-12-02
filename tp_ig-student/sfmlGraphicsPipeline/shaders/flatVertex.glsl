# version 400 // GLSL version, fit with OpenGL version
uniform mat4 projMat, viewMat, modelMat;
in vec3 vPosition;
in vec4 vColor;
out vec4 color;
in vec3 vNormal;

float map(float value, float min1, float max1, float min2, float max2){
	return min2 + (value - min1) * (max2 - min2) / (max1 - min1);
}

vec3 mapVec(vec3 value, float min1, float max1, float min2, float max2){
	return vec3(
	map(value.x, min1, max1, min2, max2),
	map(value.y, min1, max1, min2, max2),
	map(value.z, min1, max1, min2, max2)
	);
}

void main ()
{
	// Transform coordinates from local space to clipped space
	gl_Position = projMat * viewMat * modelMat * vec4 (vPosition, 1);
//	color = vColor; // RGBA color defined in [0,1]
	color = vec4(mapVec(vNormal, -1, 1, 0, 1), 1.0f);
}