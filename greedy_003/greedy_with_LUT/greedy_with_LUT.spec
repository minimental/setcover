greedy with look-up-table should

1.  read a file with the problem description: header and body,
2.  create a look-up table: key is element value, value is a list of pairs, where the pair consists of a set index, and an index locating the element in the set;
3.  create sets: a set is a data type including its cost efficiency, and a list of element data types, containing value and indices to previous and next values; every set corresponds to a line in the body of the file,
4.  organize all sets in a list,
5.  evaluate the cost efficiency of a set,
6.  count the number of elements being removed,
7.  stop and return a solution if the number of elements being removed equals the overall number of elements,
8.  keep track which set indices are part of the solution,
9.  remove an element from all sets that is currently being iterated over in the most cost-efficient set,
10. should be able to identify the most cost-efficient set after each removal of an element from all sets,
11. should choose the most cost-efficient set after having propagated through each element of the previous one,
12. iterate over all elements of a most cost-efficient set