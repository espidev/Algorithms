# Random Notes

* When computing number of subsets, it's 2^N and should be using bitmask
* __builtin_popcount(unsigned int) in the GNU C++ compiler calculates the number of 1s in a binary number (Integer.bitCount(i, j) in Java)
* __builtin_clz() -- Count leading zeroes
* std::bitset is useful for bit related stuffs
* stoi() can specify a base in the 3rd parameter
* puts() is like the most useful thing ever why have i not used it what
* greater<int> is a useful comparator function template for specifying for data structures to sort descending (ex. set<int, greater<int>)
* A.erase(unique(A.begin(), A.end()), A.end()); // make vector have only unique elements
* For C++, string.split(" ") from Java can be implemented with istringstream ss(str), and then do ss >> var to get the first string, and so on (like cin).
* C++ compilers optimize sequential array searching (row, not column), so use that when possible.
* Column searching has performance hits especially when iterating over sizes that are powers of 2 (https://stackoverflow.com/questions/12264970/why-is-my-program-slow-when-looping-over-exactly-8192-elements?rq=1)
* To specify comparator for a struct, use the operator== override
* Example: `
struct loc {
    int x, y, vx, vy;
    bool operator==(const loc& l) const {
        return (this->x == l.x && this->y == l.y && this->vx == l.vx && this->vy == l.vy);
    }
};
`
* swap(a, b) - swap two variables saving 2 lines of code 

## Hashing
* Can use C++ std::hash<T>()(value) to hash values
* Can quickly hash multiple values with XOR (^) (hash<T>()(value) ^ hash<T>()(value2))
* Example: `
struct hashing {
    size_t operator()(const loc& l) const {
        return (hash<int>()(l.x) ^ hash<int>()(l.y) ^ hash<int>()(l.vx) ^ hash<int>()(l.vy));
    }
};
` 

## Rolling Hash
* Use when you need bitmask but the number is too large (>64 digits)
* Make a map that contains every possibility of a ull key
* Each subsequent key is 1 more digit right (for right index), and 1 more digit right (for left index)

## Mo's Algorithm
* Range queries, where the queries are used to preprocess solutions.
* Sort the queries
* Maintain L and R pointer

## Shoelace Theorem

## Pick's Theorem

## Set
* Internally stores elements as a balanced binary tree (fast queries with binary search using lower_bound and upper_bound).
* By default sorts the elements by ascending order (can use unordered_set instead, but must define equality method).
* Does not allow duplicate elements.
* Useful for inserting and deleting elements in logarthmic time.
* Can compress points on a cartesian plane by inserting them into a set, and mapping it to indexes

## Sweep Line Algorithm
* Vertical line that "sweeps" right across the whole plane.
* Only stops and processes at "event points", which are vertical lines that contain points.
* Can be used to find which two points on cartesian plane are the closest.
- Keep track of index "l" while looping that is always x coordinates that are acceptable and can still be optimal (disregard far away points by x)
* Can be used to find what the total area is of overlapping rectangles.
* Method of thinking, where data is processed left to right over x coordinates on a cartesian plane.
* Iterate over x coordinates and feed into segtree (for some problems).


## Kruskal's vs. Prim's
* Prim's has to be used instead of Kruskal's when getting a subset of the minimum spanning tree.

## Bitmask
* ~ - COMPLIMENT (flips bit)
* & - AND (1 if both are 1)
* | - OR (1 if one is 1 or both is 1)
* ^ - XOR (1 if one is 1, but not when both is 1)

## Quadrangle Inequality
* f(i, j) + f(i+1, j+1) <= f(i, j+1) + f(i+1, j)
* DP optimization with this property
* Only search for > j+1 if true (nothing on the left is optimal)
* ex. Tourism (CCC19S4), apio10p1

## Sequence DP

## DP on the Interval

## Storing states in DP (2D Array)

## Prefix Sum 
* O(1) range queries
* Also prefix max, and suffix max
* Can also do prefix xor

## Prefix Sum vs Segment Tree
* Different ways to query sums (O(1) vs. O(nlogn))

## Binary Indexed Tree (Fenwick Tree)

## Adjacency List & Adjacency Matrix
* Adjacency list

## Set
* A list of values in an unique order, and is stored as a binary search tree.
* Find lookups take O(logN) time, so it's good for detecting if an item is part of a set

## Divide and Conquer
* Check USACO 12 P3

## Square Root Decomposition
* Grouping of blocks by sqrt(n)
* Update: O(1)
* Query: O(1) for complete blocks
* Query: Brue force for partial parts of blocks
* DMOJ Example: HopScotch

## Priority Queue
* When you edit values of a priority queue, the queue is not automatically updated (or ordered)
* Insert operations are automatically ordered

## Segment Tree (Range Query and Update)

It's effectively a binary tree!
<br>
[Link to Article] (https://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/)

## Disjoint set (Union Find)
* Detect if 2 items are part of the same set
* Ranking compression can be used (smaller set merged into the larger set)

## Cross + Dot Product
* Dot Product: The length of the "shadow" or "projection" that one vector has on another when put on a common point.
* Use it to find the angle between two vectors, by moving both's origin to the point of origin (0, 0)
* Use to determine if several points are on the same line without division (cross product)
* http://www.hackerearth.com/practice/notes/computational-geometry-i-1

## Trie
* Dictionary search for strings on a tree
* Nodes are characters

## Sparse Table
* RMQ and just range queries with powers of 2

## Lowest Common Ancestor

## Linear Recurrence (fibonacci)

## Dijkstra
   The notion of "relaxation" comes from an analogy between the estimate of the shortest path and the length of a helical tension spring, which is not designed for compression. Initially, the cost of the shortest path is an overestimate, likened to a stretched out spring. As shorter paths are found, the estimated cost is lowered, and the spring is relaxed. Eventually, the shortest path, if one exists, is found and the spring has been relaxed to its resting length.

## Bipartite Graph

## SPFA

## Floyd-Warshall
* aka all pairs shortest path
* Iterate over edges
* Compare direct connection weight between 2 nodes or weight between 2 nodes using node k

## Ford-Fulkerson (Edmonds-Karp) Max Flow

## Topological Sort

## Bucket grouping (Dijkstra)

## Tree Style DP

## 1D/1D DP Optimization
* Optimization of dp[i] = max/min{dp[j]+u(i,j)}
* Move variable j right over time, rather than always starting at furthest left.
* Use deque to keep track of optimal solutions
* https://sites.google.com/site/ubcprogrammingteam/news/1d1ddynamicprogrammingoptimization-parti
* check solutions/dmoj/ccoprep3p2.cpp

## SCC (Strongly Connected Components)

## Catalan Numbers
