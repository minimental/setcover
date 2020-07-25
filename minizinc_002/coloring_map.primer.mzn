/*
 * M I N I Z I N C   P R I M E R
 * =============================
 *
 * This MiniZinc primer aims at coloring a map s.t. no two adjacent states have the same color
 *
 * Taken from the MiniZinc Handbook, Release 2.4.3 (Mar 03 2020), Part 2, "A MiniZinc Tutorial", section 2.2.4 "Enumerated Types"
 * https://www.minizinc.org/doc-latest/index.html
 * 
 * "MiniZinc is a [high-level abstraction] language for specifying constrained optimization and decision problems over integers and real numbers."
 *
 * Call with
 * minizinc --solver gecode -D"Colors={black, red, white, blue};" coloring_map.primer.mzn
 */

enum Color;

var Color: western_australia;
var Color: northern_territory;
var Color: south_australia;
var Color: queensland;
var Color: new_south_wales;
var Color: victoria;
var Color: tasmania;

% adjacent countries may not match
constraint western_australia != northern_territory /\ western_australia != south_australia /\ northern_territory != south_australia /\ northern_territory != queensland /\ south_australia != queensland /\ south_australia != new_south_wales /\ south_australia != victoria /\ queensland != new_south_wales /\ new_south_wales != victoria;

solve satisfy;