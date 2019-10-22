// api.h

#ifndef api_h
#define api_h

extern void sphere(float radius, float *surface, float *volume);
extern float volCylinder(float radius, float height);
extern float sumFloat(float arr[], int numFloats);
extern double sine(float angle);
extern void printArr(FILE *output, float arr[], int numFloats);
extern void sortArr(FILE *output, float arr[], int numItems);

#endif //api_h
