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
 
 % board with intial state
 array[1..9, 1..9] of 0..9: initial_state;
 array[1..9, 1..9] of var 1..9: board;
 
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
  constraint forall (i,j in 1..9 where initial_state[i,j] != 0) (board[i,j] = initial_state[i,j]);
  
  % constraint: all row entries pairwise different
  constraint forall(i in 1..9) (alldifferent([board[i,j] | j in 1..9]));
  
  % constraint: all column entries pairwise different
  constraint forall(j in 1..9) (alldifferent([board[i,j] | i in 1..9]));
  
  % constraint: all subsquare entries must be pairwise different
  constraint forall (k,l in 0..2) (alldifferent([board[i + k*3, j + l*3] | i,j in 1..3])); 
  
  % solver mode
  solve satisfy;
  
  output 
    [if initial_state[1,j] != 0 then "\(initial_state[1,j]) " else "  " endif | j in 1..9] ++ ["\n"] ++
	[if initial_state[2,j] != 0 then "\(initial_state[2,j]) " else "  " endif | j in 1..9] ++ ["\n"] ++
	[if initial_state[3,j] != 0 then "\(initial_state[3,j]) " else "  " endif | j in 1..9] ++ ["\n"] ++
	[if initial_state[4,j] != 0 then "\(initial_state[4,j]) " else "  " endif | j in 1..9] ++ ["\n"] ++
	[if initial_state[5,j] != 0 then "\(initial_state[5,j]) " else "  " endif | j in 1..9] ++ ["\n"] ++
	[if initial_state[6,j] != 0 then "\(initial_state[6,j]) " else "  " endif | j in 1..9] ++ ["\n"] ++
	[if initial_state[7,j] != 0 then "\(initial_state[7,j]) " else "  " endif | j in 1..9] ++ ["\n"] ++
	[if initial_state[8,j] != 0 then "\(initial_state[8,j]) " else "  " endif | j in 1..9] ++ ["\n"] ++
	[if initial_state[9,j] != 0 then "\(initial_state[9,j]) " else "  " endif | j in 1..9] ++ ["\n"] ++
	["\n"] ++
	["\(board[1, j]) " | j in 1..9] ++ ["\n"] ++
	["\(board[2, j]) " | j in 1..9] ++ ["\n"] ++
	["\(board[3, j]) " | j in 1..9] ++ ["\n"] ++
	["\(board[4, j]) " | j in 1..9] ++ ["\n"] ++
	["\(board[5, j]) " | j in 1..9] ++ ["\n"] ++
	["\(board[6, j]) " | j in 1..9] ++ ["\n"] ++
	["\(board[7, j]) " | j in 1..9] ++ ["\n"] ++
	["\(board[8, j]) " | j in 1..9] ++ ["\n"] ++
	["\(board[9, j]) " | j in 1..9]