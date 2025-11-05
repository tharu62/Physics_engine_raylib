#include "raylib.h"

typedef struct{
    int degree_of_freedom;
    int degree_of_constraint;
}Component;

Component truss(){
    Component truss = {0,3};
    return truss;
}

Component bar(){
    Component bar = {1,2};
    return bar;
}

Component spring(){
    Component spring = {1,2};
    return spring;
}

Component disk(){
    Component disk = {1,2};
    return disk;
}

