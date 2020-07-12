% Now let's dissect the aggregate built-in function `forall'
% They say `forall' is a logical conjunction of the Boolean expressions
% The logical expressions are fed to `forall' as an array.
% `forall' then returns a single Boolean expression.
% I.e. forall([true, false]) should return true ^ false, which is false.

% You can form more complex and nested expressions that return an array of Boolean expressions:
% forall([true | i in 1..3])

% Or even more complex
enum atoms = { one_bound, two_bound, three_bound};
bool: candidate = forall([atoms[i] != one_bound | i in 1..3 where i > 1]);

output[
	"\(forall([true, false]))\n",
	"\(forall([true | i in 1..3]))\n",
	"\(candidate)"
]