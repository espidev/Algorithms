# Random Notes

* When computing number of subsets, it's 2^N and should be using bitmask
* __builtin_popcount(unsigned int) in the GNU C++ compiler calculates the number of 1s in a binary number (Integer.bitCount(i, j) in Java)
* std::bitset is useful for bit related stuffs
* stoi() can specify a base in the 3rd parameter
* puts() is like the most useful thing ever why have i not used it what
* greater<int> is a useful comparator function template for specifying for data structures to sort descending (ex. set<int, greater<int>)

## Set
* Internally stores elements as a balanced binary tree (fast queries with binary search using lower_bound and upper_bound).
* By default sorts the elements by ascending order.
* Does not allow duplicate elements.

## Storing states in DP (2D Array)

## Prefix Sum vs Segment Tree
* Different ways to query sums (O(1) vs. O(nlogn))

## Binary Indexed Tree (Fenwick Tree)

## Adjacency List

## Set
* A list of values in an unique order, and is stored as a binary search tree.

## Priority Queue
* When you edit values of a priority queue, the queue is not automatically updated (or ordered)

## Segment Tree (Range Query)

It's effectively a binary tree!
<br>
[Link to Article] (https://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/)

## Disjoint set (Union Find)

## Trie

## Sparse Table

## Lowest Common Ancestor

## Linear Recurrence (fibonacci)

## Dijkstra
   The notion of "relaxation" comes from an analogy between the estimate of the shortest path and the length of a helical tension spring, which is not designed for compression. Initially, the cost of the shortest path is an overestimate, likened to a stretched out spring. As shorter paths are found, the estimated cost is lowered, and the spring is relaxed. Eventually, the shortest path, if one exists, is found and the spring has been relaxed to its resting length.

## Bipartite Graph

## SPFA

## Floyd-Marshall

## Ford-Fulkerson (Edmonds-Karp) Max Flow

## Topological Sort

## Bucket grouping (Dijkstra)

## Tree Style DP

## catalan Numbers
## duowei 1265, 1350, 1457
