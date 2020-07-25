/*
 * M I N I Z I N C   P R I M E R
 * =============================
 *
 * This MiniZinc primer aims at coloring a map s.t. no two adjacent states have the same color
 *
 * Taken from the MiniZinc Handbook, Release 2.4.3 (Mar 03 2020), Part 2, "A MiniZinc Tutorial", section 2.2.5 "Complex Constraints"
 * https://www.minizinc.org/doc-latest/index.html
 *
 * Problem description:
 * "whenever m prefers another women o to his wife w, o prefers her husband to m, and whenever w prefers another man o to her husband m, o prefers his wife to w."
 * 
 * "MiniZinc is a [high-level abstraction] language for specifying constrained optimization and decision problems over integers and real numbers."
 *
 */
 
/*
 * I N P U T
 * =========
 * The rank matrix says how one is attracted by the other.
 * E.g. rank[you, me] = 0, rank[me, you] = 9 
 * means you don't care about me, but I totally dig you.
 */
enum WOMEN;
enum MEN;
array[WOMEN, MEN] of 0..9: rank_of_women;
array[MEN, WOMEN] of 0..9: rank_of_men;

/*
 * D E C I S I O N   V A R I A B L E S
 * ===================================
 * The question is: which woman will eventually choose which husband?
 */
array[WOMEN] of var MEN: womens_choice;
array[MEN] of var WOMEN: mens_choice;

/*
 * C O N S T R A I N T S
 * =====================
 * As described above (criterion for stability - the state we are after):
 * 
 * (1) woman prefers another man to her partner => That man prefers his partner to that woman.
 * (2) man prefers another woman to his partner => Than woman prefers her partner to that man.
 */

% To get a grip on the problem description, I formulated the constraint in some sort of pseudo code:
%    constraint rank[some_woman, another_man] > rank[some_woman, her_partner] -> rank[another_man, his_partner] > rank[another_man, some_woman];
%
% Do we require yet another `rank' matrix?
% For the men's choice?
% The first rank matrix states in its first row which men the first woman likes or dislikes.
% So we should also know about the men's interests.
% That's exactly how it is modeled in the tutorial.
% We're on track.
%
% The reason why we might want to introduce the seemingly redundant decision variables of the actual men's choice is that there might be more men than women.
% I don't know about the implications what I'm now mentioning. But it seems some sort of symmetric problem.

% base constraint: a men's choice is a woman; this woman's partner needs to be the same man (and vice versa)
constraint forall (w in WOMEN) (mens_choice[womens_choice[w]] == w);
constraint forall (m in MEN) (womens_choice[mens_choice[m]] == m);

constraint forall (w in WOMEN) (
	forall (m in MEN) (
		rank_of_women[w, m] > rank_of_women[w, womens_choice[w]] -> rank_of_men[m, mens_choice[m]] > rank_of_men[m, w]
	)
);

% as mentioned, the problem seems to be somewhat symmetric
constraint forall (m in MEN, w in WOMEN) (
	rank_of_men[m, w] > rank_of_men[m, mens_choice[m]] -> rank_of_women[w, womens_choice[w]] > rank_of_women[w, m]
);

solve satisfy;