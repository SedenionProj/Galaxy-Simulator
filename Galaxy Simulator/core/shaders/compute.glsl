#version 430 core

layout (local_size_x = 128, local_size_y = 1, local_size_z = 1) in;

layout (std430, binding = 0) buffer PositionBuffer {
	vec3 positions[];
};

void main() {
	uint index = gl_GlobalInvocationID.x/3;

	vec3 accel = vec3(0,0,0);
	for(int i = 0; i< 20000; i++){
		if(positions[i]!=positions[index]){
			accel += normalize(positions[i]-positions[index])/(pow(distance(positions[i],positions[index]),2)+25);
		}
	}
	//positions[index] += accel/2000000;
}