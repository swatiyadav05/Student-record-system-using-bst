# DSA Mini Project Report — PPF Week 9

## Project 1: Campus Route Finder Using Graphs

### Aim
To create a campus route finder using a graph and implement BFS and DFS.

### Problem statement
Campus locations are represented as vertices and paths as edges. The program displays connected locations, finds a route between two locations, and identifies unreachable locations.

### Data structure
The graph is represented using an adjacency list. Each vertex stores a linked list of its neighbouring vertices. The graph is undirected, so every connection is stored in both directions.

### Locations used
0 Main Gate; 1 Library; 2 Block 1; 3 Block 2; 4 Cafeteria; 5 Auditorium; 6 Parking; 7 Lab.

### Algorithms
- BFS uses a queue and a visited array. A parent array reconstructs the shortest route in an unweighted graph.
- DFS uses recursion and a visited array to display all locations reachable from a starting point.

### Test cases
| Test | Source | Destination | Expected result |
|---|---|---|---|
| Direct route | Main Gate | Library | Route with 1 edge |
| Multi-stop route | Main Gate | Auditorium | Shortest route with 3 edges |
| Unreachable | Main Gate | Lab | No route exists |

### Complexity
For an adjacency list, BFS and DFS take O(V + E) time. Their auxiliary space is O(V). An adjacency matrix uses O(V²) space; an adjacency list uses O(V + E) space.

### Result
The program represents eight campus locations, finds shortest unweighted routes using BFS, and displays reachable and disconnected locations using DFS.

---

## Project 2: Student Record Search System Using Trees

### Aim
To implement a student record system using a Binary Search Tree.

### Problem statement
Each student record contains a unique enrolment ID, name and department. The BST supports insertion, searching, deletion and sorted display.

### Data structure
The enrolment ID is the BST key. Values smaller than a node's key are stored in its left subtree; larger values are stored in its right subtree. Duplicate IDs are rejected.

### Operations
- Insert: adds a new student record in the correct BST position.
- Search: finds a record by enrolment ID.
- Delete: handles leaf, one-child and two-child cases. For two children, the inorder successor replaces the deleted node.
- Inorder: displays records in ascending ID order.
- Preorder and postorder: display the other two standard traversal orders.

### Sample data
The program starts with ten sample student records. The user can insert additional records through the menu.

### Test cases
| Test | Operation | Expected result |
|---|---|---|
| Duplicate key | Insert an existing ID | Duplicate ID rejected |
| Successful search | Search ID 106 | Matching student details displayed |
| Unsuccessful search | Search ID 999 | Student not found |
| Leaf deletion | Delete ID 101 | Leaf node removed |
| One-child deletion | First delete 101, then delete 102 | Node with one child removed |
| Two-child deletion | Restart, then delete 104 | Node with two children removed |

### Complexity
For a regular BST, search, insertion and deletion take average O(log n) time when the tree is reasonably balanced. In the worst case, a skewed tree takes O(n). Traversal takes O(n). A self-balancing AVL tree maintains O(log n) operations.

### Result
The program stores and manages student records in a BST and demonstrates insertion, duplicate handling, searching, deletion and inorder, preorder and postorder traversals.
