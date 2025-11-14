#include "RK4.h"

/**
 * velocity in x = x(t) = dx/dt = (dx^2/dt * dt) * dt = acceleration in x * dt
 * velocity in y = y(t) = dy/dt = (dy^2/dt * dt) * dt = acceleration in y * dt
 */
void vel(float* vel, float acc, float dt){
    *vel =  acc * dt;
}


void compute_RK4(vec* pos, vec acc, float dt){

    vec k1={0,0},k2={0,0},k3={0,0},k4={0,0};
    // k1
    vel(&k1.x, acc.x, dt);
    vel(&k1.y, acc.y, dt);
    // k2
    vel(&k2.x, acc.x + dt/2.0, dt + k1.x/2.0);
    vel(&k2.y, acc.y + dt/2.0, dt + k1.y/2.0);
    // k3
    vel(&k2.x, acc.x + dt/2.0, dt + k2.x/2.0);
    vel(&k2.y, acc.y + dt/2.0, dt + k2.y/2.0);
    // k4
    vel(&k2.x, acc.x + dt, dt + k3.x);
    vel(&k2.y, acc.y + dt, dt + k3.y);

    pos->x = pos->x + (dt / 6.0) * (k1.x + 2*k2.x + 2*k3.x + k4.x);
    pos->y = pos->y + (dt / 6.0) * (k1.y + 2*k2.y + 2*k3.y + k4.y);
}