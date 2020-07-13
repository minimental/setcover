/*
 * M I N I Z I N C   P R I M E R
 * =============================
 *
 * This MiniZinc primer aims at solving the SEND + MORE = MONEY problem.
 *
 * Taken from the MiniZinc Handbook, Release 2.4.3 (Mar 03 2020), Part 2, "A MiniZinc Tutorial", section 2.2.2 "Global Constraints"
 * https://www.minizinc.org/doc-latest/index.html
 * 
 * "MiniZinc is a [high-level abstraction] language for specifying constrained optimization and decision problems over integers and real numbers."
 */
 
 % enumeration
 enum letters = {D, E, M, N, O, R, S, Y};
 
 % decision variables
 array[letters] of var 0..9: stand_ins;
 
 /*
  * C O N S T R A I N T S
  * =====================
  * Either
  *
  * D + E = Y
  * 
  * or
  * 
  * D + E = Y + 10.
  *
  * Either
  *
  * N + R = E
  * 
  * or
  * 
  * N + R = E + 10
  *
  * or
  *
  * N + R + 1 = E
  *
  * or
  *
  * N + R + 1 = E + 10.
  *
  *   SEND
  * + MORE
  * ------
  *  MONEY
  */
 constraint stand_ins[D] + stand_ins[E] + 10 * stand_ins[N] + 10 * stand_ins[R] + 100 * stand_ins[E] + 100 * stand_ins[O] + 1000 * stand_ins[S] + 1000 * stand_ins[M] = 10000 * stand_ins[M] + 1000 * stand_ins[O] + 100 * stand_ins[N] + 10 * stand_ins[E] + stand_ins[Y];
 constraint stand_ins[S] > 0;
 constraint stand_ins[M] > 0;
 
 % pairwise different constraint
 % you could as well express it as `alldifferent(stand_ins)'
 constraint forall(i,j in letters where i < j) (stand_ins[i] != stand_ins[j]);
 
 % solver mode
 solve satisfy;