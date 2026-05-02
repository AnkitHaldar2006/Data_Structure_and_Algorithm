# 🗑️ Delete Node from Beginning — Linked List — C++

> Removes the head node of a singly linked list in **O(1)** time by advancing the head pointer and freeing the old node's memory.

---

## 📌 What Does This Program Do?

This program demonstrates how to **delete the first node** (head) of a singly linked list. It is one of the most fundamental linked list operations — no traversal needed, making it a constant time O(1) operation.

```
Before:  head → [ 10 ] → [ 20 ] → NULL
After:   head → [ 20 ] → NULL        (node 10 deleted & memory freed)
```

- **Time Complexity:** O(1) — no traversal required
- **Space Complexity:** O(1) — only one temporary pointer used

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
    // Build list: 10 → 20 → NULL
    Node* head = new Node(10);
    head->next = new Node(20);

    // Step 1 — Save reference to current head
    Node* temp = head;

    // Step 2 — Advance head to next node
    head = head->next;

    // Step 3 — Free the old head's memory
    delete temp;

    cout << "Deleted from beginning" << endl;
    return 0;
}
```

---

## ▶️ Output

```
Deleted from beginning
```

---

## 🧠 How It Works — Step by Step

```
Initial State:
  head
   ↓
 [ 10 | next ]──→ [ 20 | NULL ]


Step 1 — temp = head  (save old head)
  head   temp
   ↓      ↓
 [ 10 | next ]──→ [ 20 | NULL ]


Step 2 — head = head->next  (advance head)
          temp    head
           ↓       ↓
 [ 10 | next ]──→ [ 20 | NULL ]


Step 3 — delete temp  (free old head's memory)
                  head
                   ↓
               [ 20 | NULL ]

Final State:
  head → [ 20 | NULL ]   ✅
```

---

## ⚙️ Code Breakdown

| Line | Description |
|------|-------------|
| `Node* temp = head` | Saves a pointer to the current head so we don't lose it after moving `head` |
| `head = head->next` | Moves the head pointer forward — the list now starts at node 20 |
| `delete temp` | Frees the heap memory occupied by the old head node (node 10) |

---

## 📊 Complexity Analysis

| Metric | Value | Reason |
|--------|-------|--------|
| Time | O(1) | No traversal — head pointer moves forward in one step |
| Space | O(1) | Only one extra pointer `temp` is used |

> This is why deletion from the beginning is always preferred over deletion from the end — the end requires O(n) traversal to reach the second-to-last node.

---

## 🗺️ Visual — Memory Layout

```
Before deletion:
  ┌──────────────┐        ┌──────────────┐
  │  data = 10   │──next─→│  data = 20   │──next──→ NULL
  │  (head)      │        │              │
  └──────────────┘        └──────────────┘
       ↑ temp (saved)

After deletion:
  ┌──────────────┐
  │  data = 20   │──next──→ NULL
  │  (head)      │
  └──────────────┘
```

---

## ⚠️ Why `temp` is Essential

```cpp
// ❌ WRONG — memory leak!
head = head->next;   // Lost the only pointer to node 10
                     // Node 10 is now unreachable but still occupies heap memory

// ✅ CORRECT — save first, then free
Node* temp = head;
head = head->next;
delete temp;         // Memory properly released
```

Skipping `temp` causes a **memory leak** — the deleted node's memory is never returned to the OS. In long-running programs this adds up and degrades performance.

---

## 🧪 Edge Cases to Handle

| Scenario | What Happens | Fix |
|----------|-------------|-----|
| List has one node | `head->next` is `NULL` — after deletion `head = NULL` | Works correctly as-is |
| Empty list (`head == NULL`) | `head->next` crashes — undefined behaviour | Add `if (head == NULL) return;` guard |
| List has many nodes | Only the first node is removed — rest intact | Works correctly as-is |

Robust version with empty list guard:

```cpp
if (head == NULL) {
    cout << "List is empty. Nothing to delete." << endl;
    return 0;
}
Node* temp = head;
head = head->next;
delete temp;
```

---

## 🔗 Related Linked List Operations

| Operation | Time Complexity |
|-----------|----------------|
| **Delete from Beginning** ← you are here | O(1) |
| Delete from End | O(n) |
| Delete by Value | O(n) |
| Insert at Beginning | O(1) |
| Insert at End | O(n) |
| Search / Traverse | O(n) |

---

## 🏷️ Topic

Linked List → Deletion → Delete from Beginning

**Part of:** [Data_Structure_and_Algorithm](https://github.com/AnkitHaldar2006/Data_Structure_and_Algorithm)