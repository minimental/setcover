% Try to express the following in the MiniZinc language:
% In the set, for all the elements which are smaller than limit, there exists an element which is not evenly divisible by three

par int: some_limit;
array[1..4] of par int: candidates;

bool: there_exists_an_element_not_evenly_divisible_by_three = exists( [( i - ((i div 3) * 3)) == 0 | i in candidates where i < some_limit]);

output["\(there_exists_an_element_not_evenly_divisible_by_three)"]