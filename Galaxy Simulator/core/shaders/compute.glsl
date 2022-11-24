#version 430 core

layout (local_size_x = 128, local_size_y = 1, local_size_z = 1) in;

struct Particle
{
    vec4 position;
    vec4 velocity;
	vec4 acceleration;
};

layout (std430, binding = 0) buffer ParticleBuffer {
	// récupération de nos particules depuis notre CPU
	Particle p[];
};

// récupération des variables depuis notre CPU
uniform float dt;
uniform float accuracy;
uniform float gravity;
uniform float csmooth;
uniform float blackHole;

vec3 compute_force(vec3 posi){

	// calcule la force gravitationnelle de chaque particule
	vec3 f = vec3(0);
	for(int i = 0; i<accuracy*p.length(); i++){
		if(posi != p[i].position.xyz){
			vec3 v = p[i].position.xyz - posi;
			f+= gravity*normalize(v)/(pow(length(v),2)+csmooth)/accuracy;
		}
	}

	// ajoute la force du trou noir
	f+=blackHole*normalize(vec3(0)-posi.xyz)/(pow(length((vec3(0)-posi.xyz)),2)+csmooth);
	return f;
}

void main() {
	// met à jour la position des particules
	uint index = gl_GlobalInvocationID.x;

	vec3 pos = p[index].position.xyz;
	vec3 vel = p[index].velocity.xyz;
	vec3 accel = p[index].acceleration.xyz;

	// integration de verlet
	vec3 newPos = pos+vel*dt + accel * (dt*dt*0.5);
	vec3 newAccel = compute_force(pos);
	vec3 newVel = vel + (accel+newAccel) *(dt*0.5);

	// ajoute les propriétés dans buffer
	p[index].position.xyz = newPos;
	p[index].velocity.xyz = newVel;
	p[index].acceleration.xyz = newAccel;
}