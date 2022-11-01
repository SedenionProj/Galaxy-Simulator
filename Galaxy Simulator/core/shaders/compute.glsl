#version 430 core

layout (local_size_x = 128, local_size_y = 1, local_size_z = 1) in;

struct Particle
{
    vec4 position;
    vec4 velocity;
};

layout (std430, binding = 0) buffer ParticleBuffer {
	Particle p[];
};

uniform float dt;

  const float mass = 1e-6;
  const float csmooth = 1e-4;

vec3 compute_force(vec3 posi){
	vec3 f = vec3(0);
	for(int i = 0; i<1000; i++){
		vec3 dist = p[i].position.xyz - posi;
		float d = length(dist);
		f+= mass/(d*d*d+csmooth)*dist;
	}
	return f;
}

void main() {
	uint index = gl_GlobalInvocationID.x;

	vec3 pos = p[index].position.xyz;
	vec3 vel = p[index].velocity.xyz;

	vec3 accel = compute_force(pos);
	vec3 velf = vel + accel *dt;
	vec3 posf = pos+velf*dt;

	p[index].position.xyz = posf;
	p[index].velocity.xyz = velf;
	
	
}