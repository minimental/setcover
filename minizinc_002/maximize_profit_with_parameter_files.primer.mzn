/*
 * M I N I Z I N C   P R I M E R
 * =============================
 * 
 * The optimization goal is to maximize profit, given a limited amount of ingredients for cakes, and two recipes.
 * The limitations of the resources is given as parameters in a *.dzn data file.
 *
 * Taken from: "MiniZinc Handbook", Release 2.4.3 (Mar 03 2020), Part 2: "A MiniZinc Tutorial", section 2.1.3
 */
 
% parameters (upper bounds on resources)
int: flour_availability;
int: banana_availability;
int: sugar_availability;
int: butter_availability;
int: cocoa_availability;
int: maximum_number_of_banana_cakes;
int: maximum_number_of_chocolate_cakes;

constraint assert(flour_availability < 10000, "Where would you store all that stuff??");

% decision variables
var 0..maximum_number_of_banana_cakes: banana_cake;
var 0..maximum_number_of_chocolate_cakes: chocolate_cake;

% Recipes and prices stay the same (see: `maximize_profit.primer.mzn')

/*
 * Recipe 1 (banana cake)
 * ----------------------
 * 250 g   flour
 * 2   pcs banana
 * 75  g   sugar
 * 100 g   butter
 *
 * Recipe 2 (chocolate cake)
 * -------------------------
 * 200 g   flour
 * 75  g   cocoa
 * 150 g   sugar
 * 150 g   butter
 */

% flour
constraint banana_cake * 250 + chocolate_cake * 200 <= flour_availability;

% banana
constraint banana_cake * 2 <= banana_availability;

% sugar
constraint banana_cake * 75 + chocolate_cake * 150 <= sugar_availability;

% butter
constraint banana_cake * 100 + chocolate_cake * 150 <= butter_availability;

solve maximize (40 * banana_cake + 45 * chocolate_cake);