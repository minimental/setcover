/*
 * M I N I Z I N C   P R I M E R
 * =============================
 *
 * This MiniZinc primer aims at coloring a map of Australia s.t. no two adjacent states have the same color
 *
 * Taken from the MiniZinc Handbook, Release 2.4.3 (Mar 03 2020), Part 2, "A MiniZinc Tutorial"
 * https://www.minizinc.org/doc-latest/index.html
 * 
 * "MiniZinc is a [high-level abstraction] language for specifying constrained optimization and decision problems over integers and real numbers."
 */

% declaring a parameter (in the wording not to be mistaken as a `variable'), and initializing it with 3
int: nc = 3;

% declaring decision variables, and their ranges
% identifiers are made up of upper and lower case alphabet characters, digits, and underscores
% identifiers must start with an alphabet character

var 1..nc: western_australia;
var 1..nc: northern_territory;
var 1..nc: south_australia;
var 1..nc: queensland;
var 1..nc: new_south_wales;
var 1..nc: victoria;
var 1..nc: tasmania;

% constraints are expressed as boolean expressions on the decision variables
% here, it is a list of unequations

% constraint: the value of the decision variable, referred to by the identifier `western_australia', does not equal the value of the decision variable, referred to by the identifier `norther_territory'; in short: the color of Western Australia may not be the color of Northern Territory

constraint western_australia != northern_territory;

% to guarantee that no two adjacent states have the same color, one could list all possible pairs of states, regardless them being neighbors or not, and state the inequality; this would result in 21 to be considered; actually only nine are needed considering if they're neighbors or not:

% Western Australia is neighbor to Northern Territory and South Australia:

constraint western_australia != south_australia;

% Northern Territory is neighbor to Western Australia (already taken care of), South Australia, and Queensland:

constraint northern_territory != south_australia;
constraint northern_territory != queensland;

% South Australia is neighbor to Western Australia (already taken care of), Northern Territory (already taken care of), Queensland, New South Wales, and Victoria

constraint south_australia != queensland;
constraint south_australia != new_south_wales;
constraint south_australia != victoria;

% Queensland is neighbor to Northern Territory (already taken care of), South Australia (already taken care of), and New South Wales

constraint queensland != new_south_wales;

% New South Wales is neighbor to Queensland (already taken care of), South Australia (already taken care of), and Victoria

constraint new_south_wales != victoria;

% Victoria is neighbor to South Australia (already taken care of), New South Wales (already taken care of), and Tasmania.
% But since Tasmania is not considered adjacent to Victoria (they are divided by Bass Strait), no constraint is considered

% the problem is considered a `satisfaction' problem: the value of the decision variables are to satisfy the constraints ("but we don't care which one")

solve satisfy;

% output the value of the decision variables after solving for the discrete optimization problem as a list of strings: output [<string_1>, ..., <string_n>]
% note that the escape sequence `\(western_australia)' is equivalent to `show(western_australia)' which means "write the value of the decision variable referred to by `western_australia' to stdout"

output [
	"\n",
    "M A P   C O L O R I N G   P R O B L E M :   A U S T R A L I A\n",
	"=============================================================\n",
	"\n",
	"Western Australia:  \(western_australia)\n", 
	"Northern Territory: \(northern_territory)\n",
	"South Australia:    \(south_australia)\n",
	"Queensland:         \(queensland)\n",
	"New South Wales:    \(new_south_wales)\n",
	"Victoria:           \(victoria)\n",
	"Tasmania:           \(tasmania)\n"
]