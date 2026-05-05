# Case Study on AVL Tree, B Tree and B+ Tree

---

## 1. AVL Tree

### Definition
AVL Tree is a self-balancing Binary Search Tree where the height difference 
between left and right subtree of any node is at most 1.

Balance Factor:

BF = Height(Left Subtree) - Height(Right Subtree)

Possible values:
- -1
- 0
- +1

If balance factor becomes less than -1 or greater than +1, rotation is required.

---

### Rotations in AVL Tree

#### 1. LL Rotation (Left Left)
Occurs when insertion happens in left subtree of left child.

Before:
        30
       /
      20
     /
    10

After rotation:
      20
     /  \
   10    30

---

#### 2. RR Rotation (Right Right)
Occurs when insertion happens in right subtree of right child.

Before:
    10
      \
       20
         \
          30

After rotation:
      20
     /  \
   10    30

---

#### 3. LR Rotation (Left Right)
Occurs when insertion happens in right subtree of left child.

Before:
      30
     /
   10
     \
      20

After rotation:
      20
     /  \
   10    30

---

#### 4. RL Rotation (Right Left)
Occurs when insertion happens in left subtree of right child.

Before:
   10
     \
      30
     /
   20

After rotation:
      20
     /  \
   10    30

---

### Time Complexity
| Operation | Complexity |
|----------|------------|
| Search   | O(log n)   |
| Insert   | O(log n)   |
| Delete   | O(log n)   |

---

### Applications
- Database indexing
- Memory management
- Searching applications

---

## 2. B Tree

### Definition
B Tree is a self-balancing multi-way search tree used for large data storage.

### Properties
- All leaves at same level
- Node can have multiple children
- Keys stored in sorted order

For order m:
- Maximum children = m
- Minimum children = ceil(m/2)
- Maximum keys = m - 1
- Minimum keys = ceil(m/2) - 1

---

### Time Complexity
| Operation | Complexity |
|----------|------------|
| Search   | O(log n)   |
| Insert   | O(log n)   |
| Delete   | O(log n)   |

---

### Applications
- File systems
- Databases
- Indexing large files

---

## 3. B+ Tree

### Definition
B+ Tree is an extension of B Tree where all actual data is stored only in leaf nodes.

### Features
- Internal nodes store only keys
- Leaf nodes store records
- Leaf nodes linked together

---

### Advantages
- Faster range queries
- Sequential traversal possible
- Better database performance

---

### Time Complexity
| Operation | Complexity |
|----------|------------|
| Search   | O(log n)   |
| Insert   | O(log n)   |
| Delete   | O(log n)   |

---

### Applications
- DBMS
- Search engines
- File systems

---

## Conclusion
AVL Tree is useful for balanced searching in memory.
B Tree is optimized for disk storage.
B+ Tree is preferred in database systems because of efficient indexing and range queries.
