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
 * Every week golfers are divided into groups. 
 * The manual says
 *
 * "No two pairs of golfers should ever play in two groups."
 *
 * What does that say?
 * Given two pairs of golfers, pair_1 and pair_2.
 * What if pair_1 plays in group_1, and pair_2 plays in group_2?
 *
 * No.
 * No idea.
 * 
 * What about this Wikipedia entry (https://en.wikipedia.org/wiki/Kirkman%27s_schoolgirl_problem#golfers):
 * "no two people share the same group twice"
 *
 * Is it clear now?
 * Yes.
 * It never happens that two people are in the same group.
 * Sounds easy.
 * But obviously is not.
 *
 * Given 6 golfers and one week.
 * Is it possible to organize it s.t. no two people share the same group twice?
 * Yes. Put golfers 1-3 and 4-6 in a group of same size.
 * They will never share the same group twice.
 * Because they only meet once.
 *
 * Given 2 golfers and six weeks is more difficult to arrange.
 * Given a group size of 1, no two people share the same group twice, since no two people fit in one group.
 *
 * Given 4 golfers, group size of two and twelve week is even more difficult to manage.
 * week 1: (golfer 1, golfer 2), (golfer 3, golfer 4)
 * week 2: (golfer 1, golfer 3), (golfer 2, golfer 4)
 * week 3: (golfer 1, golfer 4), (golfer 2, golfer 3)
 * week 4: no more possible pairings
 * 
 * How would you model it for a fixed group size of 2?
 * What are the constraints?
 * In the past, the proposed pairing never happened before.
 * Where the "past" could be referred to as all possible permutations
 *
 * You could first think about what the possible permutations of pairings are.
 *
 * forall (i,j in 1..4 where i < j) (golfer[i], golfer[j])
 *
 * Without going too deep into implementation detail:
 * 
 * Constraint is that no arbitrary pair in one group of one week will show up in no other group
 *
 * You can start easy:
 * Choose a simple scenario which has a known solution.
 * Like in 4 golfers, 2 groups, and 2 weeks:
 * 
 * week 1: (1, 2), (3, 4)
 * week 2: (1, 3), (2, 4)
 *
 * Then write a model explicitly for this scenario.
 *
 * While the below example works for the simple scenario, I'm not trying ot reimplement the generic solution for the golfer problem, because it's too difficult.
 * I don't know what a partition is, and can therefore not implement it.
 * Also, there were used a couple of properties of sets which I don't understand.
 *
 * "MiniZinc is a [high-level abstraction] language for specifying constrained optimization and decision problems over integers and real numbers."
 *
 */
 
% There are four golfers and two groups
int: number_of_golfers = 4;
int: number_of_groups = 2;

% These four golfers are arranged in an array of decision variables
% The decision variables represent what group the golfers are currently in
% The array covers all the golfer's group assignment for all the weeks, i.e. eight decision variables here.
array[1..8] of var 1..2: group_assignment;

% no two golfers in one group shall show up in another group

% members of group 1, week 1
constraint forall (i, j in 1..2 where i < j) ((group_assignment[i] == group_assignment[j]) -> (group_assignment[i+2] != group_assignment[j+2]) /\ (group_assignment[i+4] != group_assignment[j+4]) /\ (group_assignment[i+6] != group_assignment[j+6]));

% members of group 2, week 1
constraint forall (i, j in 3..4 where i < j) ((group_assignment[i] == group_assignment[j]) -> (group_assignment[i-2] != group_assignment[j-2]) /\ (group_assignment[i+2] != group_assignment[j+2]) /\ (group_assignment[i+4] != group_assignment[j+4]));

% members of group 1, week 2
constraint forall (i, j in 5..6 where i < j) ((group_assignment[i] == group_assignment[j]) -> (group_assignment[i-4] != group_assignment[j-4]) /\ (group_assignment[i-2] != group_assignment[j-2]) /\ (group_assignment[i+2] != group_assignment[j+2]));

% members of group 2, week 2
constraint forall (i, j in 7..8 where i < j) ((group_assignment[i] == group_assignment[j]) -> (group_assignment[i-6] != group_assignment[j-6]) /\ (group_assignment[i-4] != group_assignment[j-4]) /\ (group_assignment[i-2] != group_assignment[j-2]));

% exactly two golfers per group
constraint sum (i in 1..4) (group_assignment[i] == 1) == 2;
constraint sum (i in 1..4) (group_assignment[i] == 2) == 2;
constraint sum (i in 5..8) (group_assignment[i] == 1) == 2;
constraint sum (i in 5..8) (group_assignment[i] == 2) == 2;

solve satisfy;