// sumFloat.c

#include <math.h>
#include <stdio.h>

float sumFloat(float arr[], int numFloats){
	float sum = 0.0;
	for (int i = 0; i < numFloats; i++){
		sum += arr[i];
	}
	return sum;
}

void printArr(FILE *output, float arr[], int numFloats){
	for (int i = 0; i < numFloats; i++){
		printf("%f\n", arr[i]);
		fprintf(output, "%f\n", arr[i]);
	}
}

void sortArr(FILE *output, float arr[], int numItems){
	int pt, k;
	for (int i = 0; i < numItems - 1; i++) {
		pt = i;
		k = pt + 1;
		while(k < numItems){
			if (arr[pt] > arr[k]){
				pt = k;
			}
			else{
				k += 1;
			}
		}
		double temp = arr[pt];
		arr[pt] = arr[i];
		arr[i] = temp;
	}

	for (int j = 0; j < numItems; j++){
		printf("%f\n", arr[j]);
		fprintf(output, "%f\n", arr[j]);
	}
}