// sphere.c

#include <math.h>
#include <stdio.h>

void sphere(float radius, float *surface, float *volume){
	*surface = (4 * M_PI * pow(radius, 2));
	*volume = ((4/3.0) * M_PI * pow(radius, 3));
}