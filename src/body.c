#include "body.h"


void init_rigid_body(vec verteces[20], vec vel, vec acc, vec com, float mass, rigid_body* body){
    body->shape = disk;
    for(int i=0; i<20; ++i){
        body->vertices[i] = verteces[i];
    }
    body->velocity = vel;
    body->acceleration = acc;
    body->centerOfMass = com;
    body->mass = mass;
    return;
}   


void compute_acceleration(rigid_body* body){
    // garvity + external forces.
    return;
}

void compute_position(rigid_body* body, float dt){

    compute_RK4(&body->centerOfMass, body->acceleration, dt);
    return;
}

void compute_rotation(rigid_body* body){
    switch ( body->shape )
    {
        case disk:
            
            break;
        case cube:

            break;
        case bar:

            break;
        default:
            return;
    }
    return;
}

void compute_collisions(rigid_body* body){
    switch ( body->shape )
    {
        case disk:
            
            break;
        case cube:

            break;
        case bar:

            break;
        default:
            return;
    }
    return;
}

