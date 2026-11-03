# DSA Mini Projects (C Language)

This folder contains both projects specified in the uploaded PPF Week 9 PDF.

## Project 1 — Campus Route Finder Using Graphs
- File: `campus_route_finder.c`
- Uses an undirected adjacency list with 8 campus locations.
- BFS finds a route with the minimum number of edges and reconstructs it using a parent array.
- DFS displays reachable locations.
- Lab is intentionally isolated so the unreachable/disconnected test can be demonstrated.

Compile and run:
```bash
gcc campus_route_finder.c -o campus_route_finder
./campus_route_finder
```

### Campus test cases
1. Main Gate (0) to Library (1): direct route, 1 edge.
2. Main Gate (0) to Auditorium (5): multi-stop shortest route, 3 edges.
3. Main Gate (0) to Lab (7): no route; Lab is disconnected.

## Project 2 — Student Record Search System Using Trees
- File: `student_bst.c`
- Each BST node stores enrolment ID, name and department.
- Includes 10 sample records, insertion, duplicate rejection, search, deletion and all three traversals.
- Inorder traversal displays records in ascending enrolment-ID order.
- Deletion handles leaf, one-child and two-child nodes.

Compile and run:
```bash
gcc student_bst.c -o student_bst
./student_bst
```

### BST deletion test cases (using the initial sample tree)
- Leaf: delete ID `101`.
- One child: delete ID `102` (after deleting 101, node 102 has one child, 103).
- Two children: delete ID `104` before the previous deletions.

For a clean demonstration of each deletion case, restart the program before each test because the program begins with the same 10 sample records.

## Complexity (as required by the project brief)

### Graph
- Adjacency list storage: O(V + E).
- Adjacency matrix storage (if used): O(V²).
- BFS with adjacency list: O(V + E) time; O(V) auxiliary space.
- DFS with adjacency list: O(V + E) time; O(V) auxiliary space.

### Regular BST
- Search, insertion and deletion: average O(log n) when the tree is reasonably balanced.
- Worst case: O(n) when insertion order makes the tree skewed (for example, sorted IDs).
- Traversal: O(n) time.
- A self-balancing AVL tree maintains height O(log n), keeping search/insert/delete O(log n).

## GitHub submission
Create one repository, for example `DSA-Mini-Projects`, and upload both `.c` files and this README. Add your own screenshots of the programs running in your compiler/terminal.
