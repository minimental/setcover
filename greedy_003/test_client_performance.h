#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#include "problem.h"
#include "solution.h"

void readProblemDescription(char* path, struct problem* specificProblem);
void setcover_greedy(struct problem* specificProblem, struct solution* specificSolution);