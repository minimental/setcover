/*
 * Considering the contents of section 2.2.1 "Arrays and Sets", is it possible to reformulate the set cover problem more consisely?
 */
 
 % number of sets
 par int: M;
 
 % number of elements
 par int: N;
 
 array[1..M] of set of int: problem_sets;
 array[1..M] of var set of 0..N-1: solution_sets;
 
 % decision variables
 array[1..M] of var bool: choose_set;

 % union set of chosen sets
 constraint forall (i in 1..M) (solution_sets[i] = if choose_set[i] then problem_sets[i] else {} endif);
 
 % constraints
 constraint card(array_union(solution_sets)) == N;
 
 % solver type
 solve minimize sum (i in 1..M where choose_set[i]) (1);