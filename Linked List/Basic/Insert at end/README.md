# ➕ Insert at End — Linked List — C++

> Traverses the entire list to find the tail node, then attaches the new node after it — preserving insertion order at the cost of O(n) traversal.

---

## 📌 What Does This Program Do?

This program inserts a new node at the **end** (tail) of a singly linked list. Unlike insertion at the beginning, this requires walking through every existing node to reach the last one before attaching the new node.

```
Before:  head → [ 10 ] → NULL
Insert:  val = 20
After:   head → [ 10 ] → [ 20 ] → NULL
```

- **Time Complexity:** O(n) — must traverse to the last node
- **Space Complexity:** O(1) — one new node allocated, one traversal pointer used

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
    Node* head = new Node(10);    // Existing list: 10 → NULL

    Node* newNode = new Node(20); // New node to insert at end

    // Step 1 — Traverse to the last node
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    // Step 2 — Attach new node at the end
    temp->next = newNode;

    cout << "Inserted at end" << endl;
    return 0;
}
```

---

## ▶️ Output

```
Inserted at end
```

---

## 🧠 How It Works — Step by Step

```
Initial State:
  head
   ↓
 [ 10 | NULL ]        newNode → [ 20 | NULL ]


Step 1 — temp = head = node(10)

  Loop: while (temp->next != NULL)
        temp->next = NULL  →  condition FALSE  →  loop exits immediately
        (list has only one node — temp is already at the tail)

  head    temp
   ↓       ↓
 [ 10 | NULL ]


Step 2 — temp->next = newNode

  head    temp
   ↓       ↓
 [ 10 | next ]──→ [ 20 | NULL ]

Final State:
  head → [ 10 ] → [ 20 ] → NULL   ✅
```

---

## 🗺️ Visual — Multi-Node Traversal (3-node list)

```
List: 10 → 20 → 30 → NULL    Insert: 40

  temp = node(10)
  ┌────────────┐    ┌────────────┐    ┌────────────┐
  │  10 | next │──→ │  20 | next │──→ │  30 | NULL │
  └────────────┘    └────────────┘    └────────────┘
   ↑ temp
   temp->next = node(20) ≠ NULL  →  move forward

  temp = node(20)
  ┌────────────┐    ┌────────────┐    ┌────────────┐
  │  10 | next │──→ │  20 | next │──→ │  30 | NULL │
  └────────────┘    └────────────┘    └────────────┘
                     ↑ temp
   temp->next = node(30) ≠ NULL  →  move forward

  temp = node(30)
  ┌────────────┐    ┌────────────┐    ┌────────────┐
  │  10 | next │──→ │  20 | next │──→ │  30 | NULL │
  └────────────┘    └────────────┘    └────────────┘
                                       ↑ temp
   temp->next = NULL  →  STOP — we're at the tail

  temp->next = newNode(40)
  ┌────────────┐    ┌────────────┐    ┌────────────┐    ┌────────────┐
  │  10 | next │──→ │  20 | next │──→ │  30 | next │──→ │  40 | NULL │
  └────────────┘    └────────────┘    └────────────┘    └────────────┘
  ✅ 40 inserted at end
```

---

## ⚙️ Code Breakdown

| Line | Description |
|------|-------------|
| `Node* newNode = new Node(20)` | Allocates new node on heap — `next` is `NULL` by default |
| `Node* temp = head` | Traversal pointer — keeps `head` unchanged throughout |
| `while (temp->next != NULL)` | Advances until `temp` is the last node (its `next` is NULL) |
| `temp = temp->next` | Moves one step forward in the list |
| `temp->next = newNode` | Attaches the new node after the current tail |

---

## 📊 Complexity Analysis

| Metric | Value | Reason |
|--------|-------|--------|
| Time | O(n) | Traverses all `n` nodes to reach the tail |
| Space | O(1) | Only `temp` pointer and one new node used |

> **Optimization tip:** Maintain a separate `tail` pointer alongside `head` to reduce insertion at end to O(1) — no traversal needed.

---

## 🔑 Why `while (temp->next != NULL)` and not `while (temp != NULL)`?

```cpp
// ✅ CORRECT — stops AT the last node
while (temp->next != NULL)
    temp = temp->next;
// temp is now the tail node — we can set temp->next = newNode ✅

// ❌ WRONG — goes one step too far
while (temp != NULL)
    temp = temp->next;
// temp is now NULL — we can't do temp->next = newNode (crash!) ❌
```

The loop must stop **one node before NULL** so we have a valid pointer to attach the new node to.

---

## 🧪 Test Cases

| Initial List | Insert Value | Result List |
|-------------|-------------|-------------|
| `10 → NULL` | `20` | `10 → 20 → NULL` |
| `10 → 20 → NULL` | `30` | `10 → 20 → 30 → NULL` |
| `10 → 20 → 30 → NULL` | `40` | `10 → 20 → 30 → 40 → NULL` |
| Single node `5 → NULL` | `99` | `5 → 99 → NULL` |

---

## 🚨 Edge Cases to Handle

| Scenario | Problem | Fix |
|----------|---------|-----|
| Empty list (`head == NULL`) | `temp->next` crashes — `temp` is NULL | Add `if (head == NULL) { head = newNode; return 0; }` |
| Single node | Loop never runs — `temp->next` is already NULL | ✅ Works correctly as-is |
| Long list | Works but O(n) every time | Use a `tail` pointer for O(1) insertions |

Robust version with empty list guard:

```cpp
if (head == NULL) {
    head = newNode;
} else {
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
```

---

## ⚖️ Insert at Beginning vs Insert at End

| | Insert at Beginning | Insert at End |
|--|---------------------|---------------|
| Time | O(1) | O(n) |
| Traversal needed? | No | Yes — walk to tail |
| Order preserved? | Reversed | Same as insertion order |
| Used in | Stack (push), Prepend | Queue (enqueue), Append |

---

## 🔗 Related Linked List Operations

| Operation | Time Complexity |
|-----------|----------------|
| Insert at Beginning | O(1) |
| **Insert at End** ← you are here | O(n) |
| Insert at Position | O(n) |
| Delete from Beginning | O(1) |
| Delete from End | O(n) |
| Traversal / Print | O(n) |

---

## 🏷️ Topic

Linked List → Insertion → Insert at End

**Part of:** [Data_Structure_and_Algorithm](https://github.com/AnkitHaldar2006/Data_Structure_and_Algorithm)