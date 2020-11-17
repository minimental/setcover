/*
 * Adapted to solution given in minizinc_001
 *
 * Run solver with:
 * 
 * minizinc -a --solver-time-limit 40000 --solver cbc setcover.minizinc_001.mzn .\data\sc_330_0.dzn
 */

% number of sets
par int: M;

% number of elements
par int: N;

array[1..M] of set of int: problem_sets;

% decision variables
array[1..M] of var 0..1: choose_set;

% this is the winner constraint; study it carefully
constraint forall (i in 1..N) (sum (s in 1..M where (i-1) in problem_sets[s]) (choose_set[s]) >= 1);

% solver type
solve minimize sum (i in 1..M) (choose_set[i]);

/*
 * Output works as follows:
 *
 * output <array literal>
 *
 * where `array literal' is of the form
 *
 * [ <array_element_1>, <...>, <array_element_n> ]
 *
 * The individual array elements are string expressions
 *
 * String concatenations are done using
 *
 * <string_1> ++ <string_2>
 *
 */
output [if i == 0 then "\(sum (i in 1..M) (choose_set[i])) 0\n" else "\(choose_set[i]) " endif | i in 0..M];