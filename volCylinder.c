// volCylider.c

#include <math.h>

float volCylinder(float radius, float height){
	return M_PI * pow(radius, 2) * height;
}