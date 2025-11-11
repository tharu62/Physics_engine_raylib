#include "vector2d.h"

typedef struct{
    vec position;
    vec velocity;
    vec acceleration;
    vec centerOfMass;
    vec orientation;  // ???
    
    float area;
    float density;
    float mass;  // mass = area * height * density = area * 1 * density.

} rigid_body; // two random points in the body always mantain the same distance over time. 