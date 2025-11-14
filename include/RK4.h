#ifndef RK4_H
#define RK4_H

#include <math.h>   
#include "vector.h"
#include "body.h"

void vel(float* vel, float acc, float dt);

void compute_RK4(vec* pos, vec acc, float dt);


#endif // RK_H