# Sample Output Guide

These are representative outputs for the specified test cases. The exact order of equal-length BFS routes and DFS traversal depends on adjacency-list insertion order.

## Project 1 — Campus Route Finder

### Test 1: Direct route
```text
Enter choice: 2
Select source:
0. Main Gate
1. Library
...
Enter location number: 0
Select destination:
0. Main Gate
1. Library
...
Enter location number: 1
Shortest route (minimum number of edges): Main Gate -> Library
Number of edges: 1
```

### Test 2: Multi-stop route
```text
Enter choice: 2
Enter location number: 0
Enter location number: 5
Shortest route (minimum number of edges): Main Gate -> Block 1 -> Block 2 -> Auditorium
Number of edges: 3
```
Another route of the same minimum length may be shown depending on neighbour order.

### Test 3: Unreachable destination
```text
Enter choice: 2
Enter location number: 0
Enter location number: 7
No route exists from Main Gate to Lab.
```

## Project 2 — Student Record Search System

### Inorder display (initial records)
```text
ID       Name                 Department
101      Meera Patel          IT
102      Diya Gupta           ECE
103      Rohan Kumar          CSE
104      Aarav Sharma         CSE
105      Sara Khan            CSE
106      Anaya Verma          ECE
107      Vivaan Rao           IT
108      Kabir Singh          CSE
109      Ira Joshi            ECE
110      Ishaan Das           IT
```

### Successful search
```text
Enter choice: 2
Enter enrolment ID to search: 106
Record found: ID=106, Name=Anaya Verma, Department=ECE
```

### Unsuccessful search
```text
Enter choice: 2
Enter enrolment ID to search: 999
Student with ID 999 not found.
```

### Duplicate insertion
```text
Duplicate enrolment ID 106 rejected. ID must be unique.
```

### Traversals (initial sample tree)
```text
Preorder IDs: 104 102 101 103 108 106 105 107 110 109
Postorder IDs: 101 103 102 105 107 106 109 110 108 104
```

For deletion tests, restart the program before each case:
- Leaf: delete 101.
- One child: delete 101 first, then delete 102.
- Two children: restart and delete 104.
