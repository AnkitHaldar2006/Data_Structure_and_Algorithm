# ➕ Insert at Position — Linked List — C++

> Walks to the node just before the target position, wires the new node into the chain between two existing nodes — all in O(n) time with O(1) space.

---

## 📌 What Does This Program Do?

This program inserts a new node at a **specific position** (1-based index) in a singly linked list. It navigates to the node at `pos - 1`, links the new node to the node currently at `pos`, then connects the predecessor to the new node.

```
Before:  head → [ 10 ] → [ 20 ] → NULL
Insert:  val = 15  at  pos = 2
After:   head → [ 10 ] → [ 15 ] → [ 20 ] → NULL
```

- **Time Complexity:** O(n) — traverse up to `pos - 1` steps
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
    // Build list: 10 → 20 → NULL
    Node* head = new Node(10);
    head->next = new Node(20);

    int pos = 2, val = 15;
    Node* newNode = new Node(val);

    // Step 1 — Traverse to node just BEFORE target position
    Node* temp = head;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;

    // Step 2 — Link new node to the node currently at pos
    newNode->next = temp->next;

    // Step 3 — Link predecessor to new node
    temp->next = newNode;

    cout << "Inserted at position " << pos << endl;
    return 0;
}
```

---

## ▶️ Output

```
Inserted at position 2
```

---

## 🧠 How It Works — Step by Step

```
List: 10 → 20 → NULL     Insert: val=15 at pos=2

Step 1 — Traverse to node at pos-1 = 1

  Loop: for (i = 1; i < pos - 1; i++)
        for (i = 1; i < 1; i++)  →  condition FALSE immediately
        temp stays at head = node(10) ✅

  head    temp
   ↓       ↓
 [ 10 | next ]──→ [ 20 | NULL ]
                              newNode → [ 15 | NULL ]


Step 2 — newNode->next = temp->next = node(20)

  head    temp
   ↓       ↓
 [ 10 | next ]──→ [ 20 | NULL ]
                   ↑
           [ 15 | next ]
            ↑ newNode


Step 3 — temp->next = newNode

  head    temp
   ↓       ↓
 [ 10 | next ]──→ [ 15 | next ]──→ [ 20 | NULL ]

Final State:
  head → [ 10 ] → [ 15 ] → [ 20 ] → NULL   ✅
```

---

## 🗺️ Visual — Pointer Rewiring

```
Before insertion:
  ┌────────────┐     ┌────────────┐
  │  10 | next │────→│  20 | NULL │
  └────────────┘     └────────────┘
   ↑ temp (pos-1)

                   newNode
                     ↓
                ┌────────────┐
                │  15 | NULL │
                └────────────┘

Step 2: newNode->next = temp->next  (point 15 → 20)
  ┌────────────┐     ┌────────────┐
  │  10 | next │────→│  20 | NULL │
  └────────────┘     └────────────┘
                      ↑
                ┌─────┴──────┐
                │  15 | next │
                └────────────┘

Step 3: temp->next = newNode  (point 10 → 15)
  ┌────────────┐    ┌────────────┐    ┌────────────┐
  │  10 | next │──→ │  15 | next │──→ │  20 | NULL │
  └────────────┘    └────────────┘    └────────────┘
  ✅ 15 inserted between 10 and 20
```

---

## ⚙️ Code Breakdown

| Line | Description |
|------|-------------|
| `Node* temp = head` | Traversal pointer — leaves `head` unchanged |
| `for (i = 1; i < pos - 1; i++)` | Walks `temp` to node at position `pos - 1` (the predecessor) |
| `newNode->next = temp->next` | Links new node to the node currently occupying position `pos` |
| `temp->next = newNode` | Connects the predecessor to the new node — insertion complete |

---

## ⚠️ Critical — Order of Pointer Updates

```cpp
// ✅ CORRECT — link new node forward FIRST
newNode->next = temp->next;   // Save the connection to the rest of the list
temp->next    = newNode;      // Then redirect predecessor to new node

// ❌ WRONG — data loss!
temp->next    = newNode;      // predecessor now points to newNode
newNode->next = temp->next;   // temp->next IS newNode — self-loop! rest of list lost ❌
```

Always set `newNode->next` before updating `temp->next`. Reversing the two lines creates a self-referencing loop and loses every node after the insertion point.

---

## 📊 Complexity Analysis

| Metric | Value | Reason |
|--------|-------|--------|
| Time | O(n) | Loop walks up to `pos - 1` nodes |
| Space | O(1) | Only `temp`, `newNode`, and a few variables |

---

## 🧪 Test Cases

| Initial List | pos | val | Result List |
|-------------|-----|-----|-------------|
| `10 → 20` | 1 | `5` | `5 → 10 → 20` (insert at head — special case) |
| `10 → 20` | 2 | `15` | `10 → 15 → 20` ← this code's case |
| `10 → 20` | 3 | `30` | `10 → 20 → 30` (insert at tail) |
| `10 → 20 → 30` | 2 | `99` | `10 → 99 → 20 → 30` |

---

## 🚨 Edge Cases to Handle

| Scenario | Problem | Fix |
|----------|---------|-----|
| `pos = 1` (insert at head) | Loop doesn't handle it — `newNode` must become new `head` | Handle separately before the loop |
| `pos > length + 1` | `temp` becomes `NULL` — crash on `temp->next` | Add null check inside loop |
| Empty list (`head == NULL`) | `temp` is `NULL` immediately | Guard with `if (head == NULL)` |

Robust version:

```cpp
// Insert at head
if (pos == 1) {
    newNode->next = head;
    head = newNode;
    return 0;
}

Node* temp = head;
for (int i = 1; i < pos - 1 && temp != NULL; i++)
    temp = temp->next;

if (temp == NULL) {
    cout << "Position out of bounds." << endl;
    return 0;
}

newNode->next = temp->next;
temp->next = newNode;
```

---

## ⚖️ Comparison of Insertion Operations

| Operation | Time | Traversal |
|-----------|------|-----------|
| Insert at Beginning | O(1) | None |
| Insert at End | O(n) | Walk to tail |
| **Insert at Position** ← you are here | O(n) | Walk to `pos - 1` |

---

## 🔗 Related Linked List Operations

| Operation | Time Complexity |
|-----------|----------------|
| Insert at Beginning | O(1) |
| Insert at End | O(n) |
| **Insert at Position** ← you are here | O(n) |
| Delete from Beginning | O(1) |
| Delete from End | O(n) |
| Delete at Position | O(n) |
| Traversal / Print | O(n) |

---

## 🏷️ Topic

Linked List → Insertion → Insert at Position

**Part of:** [Data_Structure_and_Algorithm](https://github.com/AnkitHaldar2006/Data_Structure_and_Algorithm)