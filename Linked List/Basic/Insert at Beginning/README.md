# ➕ Insert at Beginning — Linked List — C++

> The fastest linked list insertion — creates a new node, points it to the current head, and updates head to the new node. All done in **O(1)** time with no traversal needed.

---

## 📌 What Does This Program Do?

This program inserts a new node at the **beginning** of a singly linked list. The new node becomes the new head, and its `next` pointer is set to the old head — making it the most efficient insertion operation in a linked list.

```
Before:  head → NULL                 (empty list)
Insert:  val = 10
After:   head → [ 10 ] → NULL
```

- **Time Complexity:** O(1) — no traversal needed, just pointer updates
- **Space Complexity:** O(1) — one new node allocated

---

## 📂 Code

```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) { data = val; next = NULL; }
};

int main() {
    Node* head = NULL;       // Start with an empty list

    int val = 10;

    // Step 1 — Create the new node
    Node* newNode = new Node(val);

    // Step 2 — Point new node to the current head
    newNode->next = head;

    // Step 3 — Update head to the new node
    head = newNode;

    cout << "Inserted at beginning: " << head->data << endl;
    return 0;
}
```

---

## ▶️ Output

```
Inserted at beginning: 10
```

---

## 🧠 How It Works — Step by Step

```
Initial State:
  head = NULL


Step 1 — Create new node with val = 10
  newNode
     ↓
  [ 10 | NULL ]


Step 2 — newNode->next = head  (point to current head = NULL)
  newNode
     ↓
  [ 10 | NULL ]  ──next──→  NULL


Step 3 — head = newNode  (head now points to new node)
  head
   ↓
  [ 10 | NULL ]

Final State:
  head → [ 10 | NULL ]   ✅
```

---

## 🗺️ Visual — Inserting into a Non-Empty List

When called repeatedly, every new node is prepended to the front:

```
Start:    head → NULL

Insert 10:
  newNode = [ 10 | next ] → NULL
  head    = newNode
  Result: head → [ 10 → NULL ]

Insert 20:
  newNode = [ 20 | next ] → node(10)
  head    = newNode
  Result: head → [ 20 → 10 → NULL ]

Insert 30:
  newNode = [ 30 | next ] → node(20)
  head    = newNode
  Result: head → [ 30 → 20 → 10 → NULL ]
```

> Notice: insertion at beginning **reverses the order** — last inserted is always at the front.

---

## ⚙️ Code Breakdown

| Line | Description |
|------|-------------|
| `Node* head = NULL` | Initializes an empty list — head points to nothing |
| `new Node(val)` | Allocates a new node on the heap with `data = val` and `next = NULL` |
| `newNode->next = head` | Links the new node to the existing list (or NULL if empty) |
| `head = newNode` | Moves head to the new node — it is now the first element |

---

## 📊 Complexity Analysis

| Metric | Value | Reason |
|--------|-------|--------|
| Time | O(1) | Fixed number of pointer operations — no loop needed |
| Space | O(1) per insert | One new node allocated each time |

> This is why stacks implemented with linked lists use **prepend (insert at beginning)** for push — it's always O(1).

---

## 🔑 Order of Operations Matters

```cpp
// ✅ CORRECT order
newNode->next = head;   // 1. Link new node to old list FIRST
head = newNode;         // 2. Then update head

// ❌ WRONG order — data loss!
head = newNode;         // head now points to newNode
newNode->next = head;   // newNode->next = newNode itself → infinite loop!
```

Always link the new node to the existing list **before** updating `head`. Reversing these two lines creates a circular self-reference and loses the entire original list.

---

## 🧪 Test Cases

| Initial List | Insert Value | Result List |
|-------------|-------------|-------------|
| `NULL` (empty) | `10` | `10 → NULL` |
| `10 → NULL` | `20` | `20 → 10 → NULL` |
| `20 → 10 → NULL` | `30` | `30 → 20 → 10 → NULL` |
| `5 → 3 → 1 → NULL` | `7` | `7 → 5 → 3 → 1 → NULL` |

---

## ⚖️ Insert at Beginning vs Insert at End

| | Insert at Beginning | Insert at End |
|--|---------------------|---------------|
| Time | O(1) | O(n) |
| Traversal needed? | No | Yes — walk to last node |
| Order preserved? | Reversed | Same as insertion order |
| Used in | Stack (push), Prepend | Queue (enqueue), Append |

---

## 🔗 Related Linked List Operations

| Operation | Time Complexity |
|-----------|----------------|
| **Insert at Beginning** ← you are here | O(1) |
| Insert at End | O(n) |
| Insert at Position | O(n) |
| Delete from Beginning | O(1) |
| Delete from End | O(n) |
| Traversal / Print | O(n) |

---

## 🏷️ Topic

Linked List → Insertion → Insert at Beginning

**Part of:** [Data_Structure_and_Algorithm](https://github.com/AnkitHaldar2006/Data_Structure_and_Algorithm)