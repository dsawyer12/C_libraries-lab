
test: libTest.o sphere.o volCylinder.o sumFloat.o sine.o libapi.so
	gcc -o test libTest.c -L. -lapi -ldl

libTest: libTest.c header.h
	gcc -Wall -fPIC -c libTest.c

sphere: sphere.c
	gcc -Wall -fPIC -c sphere.c

volCylinder: volCylinder.c
	gcc -Wall -fPIC -c volCylinder.c

sumFloat: sumFloat.c
	gcc -Wall -fPIC -c sumFloat.c

sine: sine.c
	gcc -Wall -fPIC -c sine.c

libapi.so: sphere.o volCylinder.o sumFloat.o sine.o
	gcc -shared -o libapi.so sphere.o volCylinder.o sumFloat.o sine.o

clean:
	rm *.o test *.so










