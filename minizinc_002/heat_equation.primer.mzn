% first declare a set of integers to be referred to by the identifier `HEIGHT'.
% They are parameters, since they are considered fixed.
% The general form of a parameter or variable declaration is
%   <type instantiation expression>: <variable or parameter identifier> [=] <expression>;
% Here, the type instantiation expression is `set of int'.
% Here, the parameter identifier is `HEIGHT'.
% It is initialized with the parameterized range from 0 to `h'.

% parameter are height (h) and width (w)
int: w;
int: h;
float: left;
float: right;
float: upper;
float: lower;

set of int: HEIGHT = 0..h;

% Equivalently a set of integers is declared and initialized, excluding the first and last element of `HEIGHT', named `INNER_HEIGHT'.

set of int: INNER_HEIGHT = 1..h-1;

% Same holds for the width:

set of int: WIDTH = 0..w;
set of int: INNER_WIDTH = 1..w-1;

% then we need variables for all the elements' values (here: temperature t)
array[HEIGHT, WIDTH] of var float: t;

% the heat equation as such is an arithmetic constraint
% it basically says that every element's value is the arithmetic mean of its neigboring elements
constraint forall( i in INNER_HEIGHT, j in INNER_WIDTH) (
	4 * t[i, j] = t[i-1, j] + t[i+1, j] + t[i, j-1] + t[i, j+1]
);

% boundaries
% left boundary
constraint forall(i in INNER_HEIGHT) ( t[i, 0] = left );
% right boundary
constraint forall(i in INNER_HEIGHT) ( t[i, w] = right);
% upper boundary
constraint forall(j in INNER_WIDTH) ( t[0, j] = upper );
% lower boundary
constraint forall(j in INNER_WIDTH) ( t[h, j] = lower );	
	
% corners have no impact on inner element values; set to 0
constraint t[0, 0] = 0;
constraint t[0, w] = 0;
constraint t[h, 0] = 0;
constraint t[h, w] = 0;
	
% one can explicitly state `solve satisfy'; but if omitted it is set implictely
solve satisfy;