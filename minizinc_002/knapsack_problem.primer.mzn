/*
 * M I N I Z I N C   P R I M E R
 * =============================
 *
 * This MiniZinc primer aims at finding a solution to the number of indices problem
 *
 * Taken from the MiniZinc Handbook, Release 2.4.3 (Mar 03 2020), Part 2, "A MiniZinc Tutorial", section 2.2.6 "Set Constraints"
 * https://www.minizinc.org/doc-latest/index.html
 *
 * Problem description:
 * From a given set of items, choose a subset s.t. they all fit into a knapsack and the sum of their values is maximized.
 * 
 * "MiniZinc is a [high-level abstraction] language for specifying constrained optimization and decision problems over integers and real numbers."
 *
 */
 
/*
 * I N P U T
 * =========
 */
enum ITEMS;
int: capacity;

int: maximum_value;
int: maximum_weight;

array[ITEMS] of 0..maximum_value: value;
array[ITEMS] of 0..maximum_weight: weight;

/*
 * D E C I S I O N   V A R I A B L E S
 * ===================================
 */
var set of ITEMS: picked_items;

/*
 * C O N S T R A I N T S
 * =====================
 */
constraint sum (i in picked_items) (weight[i]) <= capacity;

solve maximize sum (i in picked_items) (value[i]);