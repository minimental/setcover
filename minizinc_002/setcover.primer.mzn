/*
 * M I N I Z I N C   P R I M E R
 * =============================
 *
 * This MiniZinc primer is my first attempt to solve a small set cover problem.
 *
 * The problem is based on the data set of the discrete optimization course:
 * https://github.com/discreteoptimization/setcover
 *
 */

% decision variables are integers: include (1) or exclude (0) set
var 0..1: choose_set0;
var 0..1: choose_set1;
var 0..1: choose_set2;
var 0..1: choose_set3;
var 0..1: choose_set4;
var 0..1: choose_set5;

% problem sets
set of int: set0 = {0, 3};
set of int: set1 = {0, 1, 2, 5, 6, 8};
set of int: set2 = {1, 2, 5, 6, 8};
set of int: set3 = {6, 7, 8};
set of int: set4 = {0, 3, 4, 5, 6};
set of int: set5 = {1, 2, 7, 8};

% unite chosen sets
var set of int: empty_set = {};
var set of int: solution_set_0;
solution_set_0 = if choose_set0 == 1 then set0 else empty_set endif;
var set of int: solution_set_1;
solution_set_1 = if choose_set1 == 1 then solution_set_0 union set1 else solution_set_0 endif;
var set of int: solution_set_2;
solution_set_2 = if choose_set2 == 1 then solution_set_1 union set2 else solution_set_1 endif;
var set of int: solution_set_3;
solution_set_3 = if choose_set3 == 1 then solution_set_2 union set3 else solution_set_2 endif;
var set of int: solution_set_4;
solution_set_4 = if choose_set4 == 1 then solution_set_3 union set4 else solution_set_3 endif;
var set of int: solution_set_5;
solution_set_5 = if choose_set5 == 1 then solution_set_4 union set5 else solution_set_4 endif;

% constraint: union of chosen sets must have 9 elements
constraint card (solution_set_5) == 9;

% minimize cost
solve minimize (choose_set0 + choose_set1 + choose_set2 + choose_set3 + choose_set4 + choose_set5);