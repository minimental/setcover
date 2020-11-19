#include "..\greedy_with_LUT\types.h"
#include "..\greedy_with_LUT\functions.h"

void search_engine(const struct problem *specific_problem, double cost_limit, struct solution *candidate);
int constraint_store(const struct problem *specific_problem, const struct solution *specific_solution);