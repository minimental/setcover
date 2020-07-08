% all values are intentionally kept as variables to allow for different questions to be answered
% initially borrowed money
var float: P;

% quarterly repayment
var float: R;

% interest rate
var 0.0..10.0: I;

% intermediate quarterly debts
var float: B1;
var float: B2;
var float: B3;
var float: B4;

% intermediate quarterly debts cannot take arbitrary values (constraints)
constraint B1 = P - R + P * I;
constraint B2 = B1 - R + B1 * I;
constraint B3 = B2 - R + B2 * I;
constraint B4 = B3 - R + B3 * I;

solve satisfy;