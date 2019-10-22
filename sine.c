// sine.c

#include <math.h>

double sine(float angle){

	float EPSILON = 0.000001;
	angle = angle * (M_PI / 180.0);
    double numer = 1;
    double denom = angle;

    if (angle > 0.0){
    	for (int i = 1; fabs(denom / numer) > EPSILON; i++) {
    		numer *= ((2 * i) * (2 * i + 1));
        	denom *= -1 * pow(angle, 2); 
        	angle += denom / numer;
    	}
    }

    return angle;
}



