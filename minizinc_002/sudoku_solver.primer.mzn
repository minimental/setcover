/*
 * M I N I Z I N C   P R I M E R
 * =============================
 *
 * This MiniZinc primer aims at solving 9x9 Sudoku problems.
 *
 * Taken from the MiniZinc Handbook, Release 2.4.3 (Mar 03 2020), Part 2, "A MiniZinc Tutorial", section 2.2.3 "Conditional Expressions"
 * https://www.minizinc.org/doc-latest/index.html
 * 
 * "MiniZinc is a [high-level abstraction] language for specifying constrained optimization and decision problems over integers and real numbers."
 */
 
 % include global constraint
 include "alldifferent.mzn";
 
 int: number_of_squares = 9;
 int: number_of_subsquares = 3;
 
 set of int: range_of_digits = 1..9;
 
 % board with intial state
 array[range_of_digits, range_of_digits] of 0..9: initial_state;
 array[range_of_digits, range_of_digits] of var range_of_digits: board;
 
 /*
  * C O N S T R A I N T S
  * =====================
  * 
  * (0) Fixed entries
  * (1) All row entries must be pairwise different
  * (2) All column entries must be pairwise different
  * (3) All subsquare entries must be pairwise different
  *
  */
  
  % constraint: fixed entries of initial state
  constraint forall (i,j in range_of_digits where initial_state[i,j] != 0) (board[i,j] = initial_state[i,j]);
  
  % constraint: all row entries pairwise different
  constraint forall(i in range_of_digits) (alldifferent([board[i,j] | j in 1..9]));
  
  % constraint: all column entries pairwise different
  constraint forall(j in range_of_digits) (alldifferent([board[i,j] | i in 1..9]));
  
  % constraint: all subsquare entries must be pairwise different
  constraint forall (k,l in 0..2) (alldifferent([board[i + k*3, j + l*3] | i,j in 1..3])); 
  
  % solver mode
  solve satisfy;
  
  output [
	"\(board[i,j])" 
	++ 
	if j mod number_of_subsquares == 0
		then if j == number_of_squares then 
			if i mod number_of_subsquares == 0 then "\n\n" else "\n" endif
		else
			"  "
		endif
	else
		" "
	endif
    | i,j in range_of_digits 
  ]