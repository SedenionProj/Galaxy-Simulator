#version 430 core

layout (local_size_x = 128, local_size_y = 1, local_size_z = 1) in;

struct Particle
{
    vec4 position;
    vec4 velocity;
	vec4 acceleration;
};

layout (std430, binding = 0) buffer ParticleBuffer {
	Particle p[];
};

uniform float dt;
uniform float accuracy;
uniform float gravity = 1e-8;
uniform float csmooth = 1e-5;

vec3 compute_force(vec3 posi){
	vec3 f = vec3(0);
	for(int i = 0; i<accuracy*p.length(); i++){
		if(posi != p[i].position.xyz){
			vec3 v = p[i].position.xyz - posi;
			f+= gravity*normalize(v)/(pow(length(v),2)+csmooth)/accuracy;
		}
	}
	return f;
}

void main() {
	uint index = gl_GlobalInvocationID.x;

	vec3 pos = p[index].position.xyz;
	vec3 vel = p[index].velocity.xyz;
	vec3 accel = p[index].acceleration.xyz;

	vec3 newPos = pos+vel*dt + (dt*dt*0.5);
	vec3 newAccel = compute_force(pos);
	vec3 newVel = vel + (accel+newAccel) *(dt*0.5);

	p[index].position.xyz = newPos;
	p[index].velocity.xyz = newVel;
	p[index].acceleration.xyz = newAccel;
	
	
}