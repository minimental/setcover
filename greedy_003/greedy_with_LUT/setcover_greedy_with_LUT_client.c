#include <stdio.h>

#include "types.h"
#include "functions.h"

int main(int nargs, char** args) {
	
	// catch missing argument
	if (nargs != 2) {
		printf("Error: Program requires path to problem description file as an argument.");
		return -1;
	}
	
	char* output;
	char* path = args[1];
	
	// solve problem
	greedy_with_LUT(path, &output);
	
	// write output to stdout
	printf("%s", output);
	
}