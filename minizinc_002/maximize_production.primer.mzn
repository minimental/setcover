/*
 * M I N I Z I N C   P R I M E R
 * =============================
 *
 * This MiniZinc primer aims at maximizing profit by selling products with limited resources.
 *
 * Taken from the MiniZinc Handbook, Release 2.4.3 (Mar 03 2020), Part 2, "A MiniZinc Tutorial"
 * https://www.minizinc.org/doc-latest/index.html
 *
 * Section 2.2.1 "Arrays and Sets", based on Lisiting 2.2.2
 * 
 * "MiniZinc is a [high-level abstraction] language for specifying constrained optimization and decision problems over integers and real numbers."
 */
 
 % What is an `enumeration'? If it is the same than in Java, then it is an array of key-value-pairs of string literals and integers.
 enum Products;
 
 /*
  * semantically, the following defines what you'll get when selling a unit of Product 0, for example.
 * grammatically, it is pretty different from, say, C.
 * from my understanding, an array is consecutive space in memory
 * where as an entry of the enumeration of `Products' can be used to point to an entry of the array
 * e.g. if `Products' was defined as `{PRODUCT_0, PRODUCT_1, PRODUCT_2}', you could use profit[PRODUCT_1] to point to the second entry of the `profit' array, returning an integer
 *
 * enums are defined in the following fashion:
 * <enum identifier> = { <enumeration_0>, ..., <enumeration_N-1>}, where only one enumeration entry is needed
 *
 * arrays are defined in a similar fashion:
 * <array identifier> = [ <array_entry_0>, ..., <array_entry_N-1> ]
 */
array[Products] of int: profit;

% we are doing the same thing for resources:
% there are an indefinite number of resources, and they will be enumerated
enum Resources;

% resources are limited
% these are limited by storage space, or capacity
array[Resources] of int: capacity;

% given a product and a resource, we can tell what the maximum number of units are
% ...
% no
% ...
% i didn't get that one right
% given a product, the number says how many (given) resources are req'd to produce _one_ product
% they call it `consumption'
array[Products, Resources] of int: consumption;

% one can limit the range of variables by including an `assert' constraint
% `assert' takes two arguments: boolean expression, and a string literals
% if the boolean expression is false, execution is terminated and the provided string is issued as an error message
constraint assert(
	forall(products in Products, resources in Resources) (consumption[products, resources] >= 0),
	"negative consumption found"
);

% the operator `min' is associated with the following syntax:
% 	min (<set to operate on>) () ...
% ...
% no
% ...
% this is special syntax that needs a reference to the manual
% (...)
% Ok, now, this is REALLY complicated and new.
% It starts off with sth called `list and set comprehensions' (deutsch: `Umfang')
% Check out this statement:
%
% i + j | i,j in 1..3 where i < j
%
% If you're used to C, like I am, this is pretty new.
% What does it do?
% How does it translate to C?
% What's that bar `|'?
% Before I gonna dissect this, I'll try to express it in C:
%
% int comprised_list[1 + 2];
% 
% for (int j = 0; j < 3; ++j)
%	for (int i = 0; i < j; ++i) {
%		comprised_list[k] = i + j;
%		++k;
%	}
%
% Admittedly, the C code is longer.
% And not necessarily easier to understand.
% Of course, I'm used to C, so it doesn't take me too long to find out about its intentions
% But describing it the way above is much more math-like, it's concise.
% It's great that it's possible to express the same thing in different ways
% And if list comprehensions happen to be more complicated than the one given above, the C code equivalent might get pretty complicated
% So we should embrace this leveraging of abstraction level.
% And get used to it.
% Otherwise we'll have a hard time surviving the progress.
% The structure of a short `list comprehensions', like the example given above, is as follows:
%
% <expression> | <identifier>, ..., <identifier> in <array expression> where <boolean expression>
%
% The smart guys out there decided to summarize the pattern `<identifier>, ..., <identifier>', and name it `generator'.
% I don't know why.
% I'm just learning it by hard.
% That's my only chance for now. :D
% Ok.
% So we have an expression like
%
% <expression> | <generator> in <array expression> where <boolean expression>
%
% The part after and including `where' is optional
% It's an additional filter on the array expression
%
% The output of a `list comprehension' is a single array.
% Not a 2-dimensional array, not a 3-dimensional array.
% A 1-dimensional array, a single array.
% The above given example would do the following:
% 
% Generate the 2-dim array 
%
% [|
%	1, 2, 3 |
%   1, 2, 3 |
%   1, 2, 3
% |]
%
% where lines correspond to i = 1..3
% and columns correspond to j = 1..3
%
% Then the filter applies:
%
% [|
%	2, 3 |
%	3 |
%   empty array
% |]
%
% The result is then the array
%
% [5, 3]
%
% Correct?
% No.
% 
% Take a second look at all the possible permutations of a 2-tuple of integers in the range 1..3:
%
% (1,1), (1,2), (1,3), (2,1), (2,2), (2,3), (3,1), (3,2), (3,3)
%
% Now create a new array of 2-tuples where the second element is strictly greater than the first one:
%
% (1,2), (1,3), (2,3)
%
% Take the sum:
%
% [3, 4, 5]
%
% That's it.
%
% Syntactically correct initialization of an array with the comprised list:
%
% array[1..3] of int: some = [i + j | i,j in 1..3 where i < j];
%
% Note that the index ranges have to match.
% The following won't work:
%
% array[0..2] of int: some = [i + j | i,j in 1..3 where i < j];
%
% Now you know about comprised lists.
% 
% We had to delve into the generator call expressions to understand the following:
%
% int: mproducts = max (p in Products) (<boolean expression>)
%
% is equivalent to
%
% int par: mproducts = max (<boolean expression> | p in Products)
%
% because the former is considered a `generator call', a special syntax to be used in MiniZinc
%
% What they did is nest another generator call for the boolean expression, namely
%
% min (<generator expression>) (<boolean expression>)
%
% or, to be explicit,
%
% min (r in Resources where consumption[p, r] > 0) (capacity[r] div consumption[p, r])
%
% Huh?
% Wait.
% Shouldn't this be stated the other way around?
%
% No.
%
% The first expression in parentheses is a generator expression.
% But the second expression in parantheses is not a boolean expression
% There is no need for it to be a Boolean expression
% It just needs to be an expression.
% Usually on the elements provided in the generator expression
% But what does it do in this case?
% It does an integer division on elements of the 1-dim `capacity' array
%
% capacity[r] div consumption[p, r]
%
% returns a 1-dim array of elements in `capacity', divided by elements in `consumption'
%
% What does
%
% min (r in Resources where consumption[p, r] > 0) (capacity[r] div consumption[p, r])
%
% do?
%
% Finds the smallest ratio capacity/consumption, given that consumption is positive
% This corresponds to the limiting resource when creating a product.
% Say, you got 6 bananas to bake banana cake where each banana cake requires 2 bananas.
% Then you can bake 3 banana cakes
% If there's enough flour to bake 12 banana cakes, you can still bake only 3 banana cakes, since bananas are the limiting resource.
% So, in our example, `min (...)' returns the minimum number of products that we can produce, given the limited amount of resources.
% max (p in Products) (...) then finds the maximum number of products we can possibly produce, given the limited amount of resources

par int: maximum_number_of_products = max (p in Products) (
	min (r in Resources where consumption[p, r] > 0) (capacity[r] div consumption[p, r])
);

/*
 * D E C I S I O N   V A R I A B L E S
 * ===================================
 *
 * Next are the actual decision variables.
 * These need to be marked as such explicitely.
 * While the parameter keyword may be omitted, this is not the case for decision variables
 *
 * The decision variables form the answer to the actual question:
 * How much units of which product need to be produced to maximize profit.
 *
 * We can express this as an array of products, two in our example, where each array element is an integer of the actual quantity
 *
 */
 array[Products] of var 1..maximum_number_of_products: produce;
 
 % To my surprise, the used resources are also introduced as decision variables.
 % I would have expected it to be a mere consequence of the numbers of products being produced
 % But maybe they did so to reformulate the problem.
 % Maybe this allows to formulate yet another optimization problem.
 % We'll see about that.
 
 array[Resources] of var 1..max(capacity): used;
 
 /*
  * C O N S T R A I N T S
  * =====================
  *
  * All problem solving is about satisfying constraints.
  * 
  * The basic statement of the production problem is:
  * "You cannot produce more than you have"
  *
  * While somehow obvious, this needs to be expressed formally.
  * 
  * Our first constraint is an arithmetic constraint.
  * It states how many of the resources are actually used.
  *
  * The second constraint limits the use.
  */
  
  constraint forall (r in Resources) (
	used[r] = sum (p in Products) (produce[p] * consumption[p, r])
  );
  constraint forall(r in Resources) (used[r] <= capacity[r]);
  
/*
 * S O L V E R
 * ===========
 * 
 * There are three types of solving a problem:
 * 	
 *    1. Satisfying a set of constraints
 *    2. Minimization/Maximation problem
 *
 * The minimization/maximization problem is harder, since it simultaneously have to satisfy a set of constraints AND find an extrema
 *
 */
 
 solve maximize sum (p in Products) (profit[p] * produce[p]);
 
 % This is it.
 % Modeling done.
 % You may format the results nicely.
 % But you don't have to.