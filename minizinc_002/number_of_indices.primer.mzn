/*
 * M I N I Z I N C   P R I M E R
 * =============================
 *
 * This MiniZinc primer aims at finding a solution to the number of indices problem
 *
 * Taken from the MiniZinc Handbook, Release 2.4.3 (Mar 03 2020), Part 2, "A MiniZinc Tutorial", section 2.2.5 "Complex Constraints"
 * https://www.minizinc.org/doc-latest/index.html
 *
 * Problem description:
 * Choose four natural numbers including 0 s.t. the first number says how many times 0 shows up in the four numbers, the second number says how many times 1 shows up in the four numbers, and so on. 
 * 
 * "MiniZinc is a [high-level abstraction] language for specifying constrained optimization and decision problems over integers and real numbers."
 *
 */

/*
 * D E C I S I O N   V A R I A B L E S
 * ===================================
 */

array[1..4] of var 0..4: indices;

/*
 * C O N S T R A I N T S
 * =====================
 */
constraint forall (j in 1..4) (indices[j] == sum (i in 1..4 where indices[i] == j-1) (1));

solve satisfy;