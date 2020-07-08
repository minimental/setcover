/*
 * M I N I Z I N C   P R I M E R
 * =============================
 * 
 * The optimization goal is to maximize profit, given a limited amount of ingredients for cakes, and two recipes.
 *
 * Taken from: "MiniZinc Handbook", Release 2.4.3 (Mar 03 2020), Part 2: "A MiniZinc Tutorial", section 2.1.2
 */
 
/*
 * Resources
 * --------- 
 * 4   kg  flour
 * 6   pcs banana
 * 2   kg  sugar
 * 500 g   butter
 * 500 g   cocoa
 *
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
 *
 * Prices
 * ------
 * 4.5 AUD chocolate cake
 * 4   AUD banana cake
 */
 
 % decision variables: number of chocolate cakes and number of banana cakes to be produced
 % there is a maximum of 3 banana cakes (limiting resource: bananas) and a maximum of 3 chocolate cakes (limiting resource: butter)
 
 var 0..3: banana_cake;
 var 0..3: chocolate_cake;
 
 % constraints are linear inequalities with individual resources as upper limits
 % flour
 constraint banana_cake * 0.25 + chocolate_cake * 0.2 <= 4;
 
 % banana
 constraint banana_cake * 2 <= 6;
 
 % sugar
 constraint banana_cake * 0.075 + chocolate_cake * 0.15 <= 2;
 
 % butter
 constraint banana_cake * 0.1 + chocolate_cake * 0.15 <= 0.5;
 
 % cocoa
 constraint chocolate_cake * 0.075 <= 0.5;

solve maximize 4 * banana_cake + 4.5 * chocolate_cake;

output [
	"number of banana cake(s):     \(banana_cake)\n",
	"number of chocolate cakes(s): \(chocolate_cake)\n"
];