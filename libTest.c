// libTest.c

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include "api.h"

int main(int argc, char const *argv[]){

	void *handle;
	char *err;
	int numFloats;
	float surface, volume, radius, height;
	double angle;
	float arr[8];

	void (*sphere_d)(float radius, float *surface, float *volume);
	float (*volCylinder_d)(float radius, float height);
	float (*sumFloat_d)(float arr[], int numFloats);
	double (*sine_d)(float angle);
	void (*printArr_d)(FILE *output, float arr[], int numFloats);
	void (*sortArr_d)(FILE *output, float arr[], int numItems);

	FILE *output = fopen("output.doc", "w");
	if (output == NULL){
		perror("Error opening file");
		exit(1);
	}

	handle = dlopen("./libapi.so", RTLD_LAZY);
	if (handle == (void*)0){
		fputs(dlerror(), stderr);
		exit(-1);
	}

	sphere_d = dlsym(handle, "sphere");
	err = dlerror();
	if (err != NULL){
		fputs(err, stderr);
		exit(-1);
	}
	volCylinder_d = dlsym(handle, "volCylinder");
	err = dlerror();
	if (err != NULL){
		fputs(err, stderr);
		exit(-1);
	}
	sumFloat_d = dlsym(handle, "sumFloat");
	err = dlerror();
	if (err != NULL){
		fputs(err, stderr);
		exit(-1);
	}
	sine_d = dlsym(handle, "sine");
	err = dlerror();
	if (err != NULL){
		fputs(err, stderr);
		exit(-1);
	}
	printArr_d = dlsym(handle, "printArr");
	err = dlerror();
	if (err != NULL){
		fputs(err, stderr);
		exit(-1);
	}
	sortArr_d = dlsym(handle, "sortArr");
	err = dlerror();
	if (err != NULL){
		fputs(err, stderr);
		exit(-1);
	}

	printf("SPHERE\n");
	fprintf(output, "SPHERE\n");
	printf("Enter the radius value: ");
	scanf("%f", &radius);
	sphere(radius, &surface, &volume);
	printf("The sphere surface area is: %f\n", surface);
	printf("The sphere volume is: %f\n", volume);
	fprintf(output, "The sphere surface area is: %f\n", surface);
	fprintf(output, "The sphere volume is: %f\n", volume);

	printf("\nCYLINDER\n");
	fprintf(output, "\nCYLINDER\n");
	printf("Enter the value of the radius: ");
	scanf("%f", &radius);
	printf("Enter the value of the height: ");
	scanf("%f", &height);
	printf("The cylinder volume is: %f\n", (*volCylinder_d)(radius, height));
	fprintf(output, "The cylinder volume is: %f\n", (*volCylinder_d)(radius, height));

	printf("\nSUM OF ARRAY ELEMENTS\n");
	fprintf(output, "\nSUM OF ARRAY ELEMENTS\n");
	printf("Enter the number of elements: ");
	scanf("%i", &numFloats);
	for (int i = 0; i < numFloats; i++){
		printf("Enter value %i: ", i+1);
		scanf("%f", &arr[i]);
	}
	printf("The array in unsorted order: \n");
	fprintf(output, "The array in unsorted order: \n");
	(*printArr_d)(output, arr, numFloats);
	printf("The array in sorted ascending order: \n");
	fprintf(output, "The array in sorted ascending order: \n");
	(*sortArr_d)(output, arr, numFloats);
	// In the case of sorted vs unsorted time complexity,
	// the sorted will be faster due to the reduced time to compare
	// values withing the conditional loop.
	printf("The sum of the values is: %f\n", (*sumFloat_d)(arr, numFloats));
	fprintf(output, "The sum of the values is: %f\n", (*sumFloat_d)(arr, numFloats));

	printf("\nSINE\n");
	fprintf(output, "\nSINE\n");
	for (int i = 0; i < 3; i++){
		printf("Enter the angle: ");
		scanf("%lf", &angle);
		printf("The sin of %lf is: %lf\n", angle, (*sine_d)(angle));
		fprintf(output, "The sin of %lf is: %lf\n", angle, (*sine_d)(angle));
	}

	return 0;
}
















