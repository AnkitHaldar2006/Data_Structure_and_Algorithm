# 🗑️ Delete Node from End — Linked List — C++

> Traverses to the second-to-last node, frees the tail, and sets its `next` to `NULL` — all in O(n) time with O(1) space.

---

## 📌 What Does This Program Do?

This program demonstrates how to **delete the last node** (tail) of a singly linked list. Unlike deletion from the beginning which is O(1), deleting from the end requires **traversing the entire list** to reach the node just before the tail.

```
Before:  head → [ 10 ] → [ 20 ] → NULL
After:   head → [ 10 ] → NULL        (node 20 deleted & memory freed)
```

- **Time Complexity:** O(n) — must traverse to find the second-to-last node
- **Space Complexity:** O(1) — only one traversal pointer used

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

    // Step 1 — Traverse to second-to-last node
    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    // Step 2 — Free the last node
    delete temp->next;

    // Step 3 — Detach the deleted node
    temp->next = NULL;

    cout << "Deleted from end" << endl;
    return 0;
}
```

---

## ▶️ Output

```
Deleted from end
```

---

## 🧠 How It Works — Step by Step

```
Initial State (list: 10 → 20 → NULL):

  head    temp
   ↓       ↓
 [ 10 | next ]──→ [ 20 | NULL ]


Traversal Loop: while (temp->next->next != NULL)
  temp->next       = node(20)
  temp->next->next = NULL   →  condition FALSE → loop never runs
  (temp already at second-to-last node — index 0 in a 2-node list)


Step 2 — delete temp->next  (free node 20)
  head    temp
   ↓       ↓
 [ 10 | next ]──→ [  ✗ freed ✗ ]


Step 3 — temp->next = NULL  (detach pointer)
  head    temp
   ↓       ↓
 [ 10 | NULL ]

Final State:
  head → [ 10 | NULL ]   ✅
```

---

## ⚙️ Code Breakdown

| Line | Description |
|------|-------------|
| `Node* temp = head` | Start traversal pointer at the head |
| `while (temp->next->next != NULL)` | Move forward until `temp` is the second-to-last node |
| `delete temp->next` | Frees the heap memory of the last node |
| `temp->next = NULL` | Cleanly detaches the dangling pointer — new tail is set |

---

## 📊 Complexity Analysis

| Metric | Value | Reason |
|--------|-------|--------|
| Time | O(n) | Must walk the entire list to find the second-to-last node |
| Space | O(1) | Only one pointer `temp` used — no extra data structure |

> This is why **deletion from the beginning is O(1)** but **deletion from the end is O(n)** — a key difference to remember for interviews.

---

## 🗺️ Visual — Multi-Node Example (3 nodes)

```
List: 10 → 20 → 30 → NULL

  Step 0: temp = head = node(10)
  ┌────────────┐    ┌────────────┐    ┌────────────┐
  │  10 | next │──→ │  20 | next │──→ │  30 | NULL │
  └────────────┘    └────────────┘    └────────────┘
   ↑ temp

  Loop: temp->next->next = node(30)->next = NULL? NO → keep going
  temp = temp->next → temp = node(20)

  ┌────────────┐    ┌────────────┐    ┌────────────┐
  │  10 | next │──→ │  20 | next │──→ │  30 | NULL │
  └────────────┘    └────────────┘    └────────────┘
                     ↑ temp

  Loop: temp->next->next = NULL? YES → STOP

  delete temp->next → free node(30)
  temp->next = NULL

  ┌────────────┐    ┌────────────┐
  │  10 | next │──→ │  20 | NULL │
  └────────────┘    └────────────┘
                     ↑ new tail ✅
```

---

## ⚠️ Critical Bug — The Loop Condition

```cpp
// ✅ CORRECT — stops at second-to-last node
while (temp->next->next != NULL)

// ❌ WRONG — stops at last node, can't delete it cleanly
while (temp->next != NULL)
// temp would be at the last node — temp->next is already NULL
// you've lost the reference to the second-to-last node
```

The condition `temp->next->next != NULL` ensures `temp` lands on the **second-to-last** node — the one that needs its `next` pointer nulled after deletion.

---

## 🚨 Edge Cases to Handle

| Scenario | Problem | Fix |
|----------|---------|-----|
| Empty list (`head == NULL`) | `temp->next->next` crashes instantly | Add `if (head == NULL)` guard |
| Single node list | `temp->next` is NULL — `temp->next->next` crashes | Add `if (head->next == NULL)` guard |
| Two-node list | Works correctly — loop condition is immediately false | ✅ No fix needed |
| Many nodes | Works correctly — loop walks to second-to-last | ✅ No fix needed |

Robust version with guards:

```cpp
if (head == NULL) {
    cout << "List is empty." << endl;
    return 0;
}
if (head->next == NULL) {
    delete head;
    head = NULL;
    cout << "Deleted only node." << endl;
    return 0;
}
Node* temp = head;
while (temp->next->next != NULL)
    temp = temp->next;
delete temp->next;
temp->next = NULL;
```

---

## ⚖️ Delete from Beginning vs Delete from End

| | Delete from Beginning | Delete from End |
|--|----------------------|-----------------|
| Time | O(1) | O(n) |
| Traversal needed? | No | Yes — walk to second-to-last |
| Pointer updated | `head` | `second-to-last->next` |
| Risk | Empty list | Empty list + single node list |

---

## 🔗 Related Linked List Operations

| Operation | Time Complexity |
|-----------|----------------|
| Delete from Beginning | O(1) |
| **Delete from End** ← you are here | O(n) |
| Delete by Value | O(n) |
| Insert at Beginning | O(1) |
| Insert at End | O(n) |
| Search / Traverse | O(n) |

---

## 🏷️ Topic

Linked List → Deletion → Delete from End

**Part of:** [Data_Structure_and_Algorithm](https://github.com/AnkitHaldar2006/Data_Structure_and_Algorithm)