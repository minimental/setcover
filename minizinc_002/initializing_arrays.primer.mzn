array[1..2] of set of int : problem_sets;
array[1..2] of var set of 0..2: solution_sets;

array[1..2] of var bool: choose_set;

constraint forall (i in 1..2) (solution_sets[i] = if choose_set[i] then problem_sets[i] else {} endif);

constraint card(array_union(solution_sets)) == 2;

solve satisfy;