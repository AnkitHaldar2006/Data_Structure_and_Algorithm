# 🗑️ Delete Node at Position — Linked List — C++

> Walks to the node just before the target position, rewires the `next` pointer to skip the deleted node, and frees its memory — in O(n) time with O(1) space.

---

## 📌 What Does This Program Do?

This program deletes a node at a **specific position** (1-based index) in a singly linked list. It first traverses to the node immediately **before** the target, then bypasses and frees the target node.

```
List:      head → [ 10 ] → [ 20 ] → [ 30 ] → NULL
Delete:    position = 2  (node with value 20)

Result:    head → [ 10 ] → [ 30 ] → NULL
```

- **Time Complexity:** O(n) — traversal to position `pos - 1`
- **Space Complexity:** O(1) — no extra data structure used

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
    // Build list: 10 → 20 → 30 → NULL
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    int pos = 2;             // Delete node at position 2 (1-based)

    Node* temp = head;

    // Step 1 — Traverse to node just BEFORE the target position
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;

    // Step 2 — Save reference to node being deleted
    Node* delNode = temp->next;

    // Step 3 — Bypass the deleted node
    temp->next = delNode->next;

    // Step 4 — Free memory
    delete delNode;

    cout << "Deleted from position " << pos << endl;
    return 0;
}
```

---

## ▶️ Output

```
Deleted from position 2
```

---

## 🧠 How It Works — Step by Step

```
List: 10 → 20 → 30 → NULL     pos = 2

Step 1 — Traverse to node before position 2 (i.e. node at pos-1 = 1)

  Loop: for (i = 1; i < pos - 1; i++)
        for (i = 1; i < 1; i++)  →  condition FALSE immediately
        temp stays at head = node(10) ✅


Step 2 — delNode = temp->next = node(20)

  head    temp
   ↓       ↓
 [ 10 | next ]──→ [ 20 | next ]──→ [ 30 | NULL ]
                    ↑
                  delNode


Step 3 — temp->next = delNode->next = node(30)

  head    temp                         
   ↓       ↓                           
 [ 10 | next ]─────────────────→ [ 30 | NULL ]
                    ↑
              [ 20 | next ]  ← bypassed, still in memory


Step 4 — delete delNode  →  free node(20)

  head    temp                         
   ↓       ↓                           
 [ 10 | next ]──→ [ 30 | NULL ]   ✅
```

---

## ⚙️ Code Breakdown

| Line | Description |
|------|-------------|
| `int pos = 2` | 1-based position of the node to delete |
| `Node* temp = head` | Traversal pointer — starts at head |
| `for (i = 1; i < pos - 1; i++)` | Moves `temp` to the node just **before** position `pos` |
| `Node* delNode = temp->next` | Saves a pointer to the node that will be deleted |
| `temp->next = delNode->next` | Rewires the link — predecessor now points to successor |
| `delete delNode` | Frees the heap memory of the removed node |

---

## 📊 Complexity Analysis

| Metric | Value | Reason |
|--------|-------|--------|
| Time | O(n) | Loop traverses up to `pos - 1` steps |
| Space | O(1) | Only two extra pointers — `temp` and `delNode` |

---

## 🗺️ Visual — Pointer Rewiring

```
Before:
  ┌────────────┐    ┌────────────┐    ┌────────────┐
  │  10 | next │──→ │  20 | next │──→ │  30 | NULL │
  └────────────┘    └────────────┘    └────────────┘
   ↑ temp (pos-1)    ↑ delNode (pos)

Rewire: temp->next = delNode->next

  ┌────────────┐    ┌────────────┐    ┌────────────┐
  │  10 | next │─── │  20 | next │──→ │  30 | NULL │
  └────┬───────┘    └────────────┘    └────────────┘
       └──────────────────────────────────↑
                    (20 bypassed)

After delete delNode:
  ┌────────────┐    ┌────────────┐
  │  10 | next │──→ │  30 | NULL │
  └────────────┘    └────────────┘
  ✅ Node 20 removed, memory freed
```

---

## 🧪 Test Cases

| List | Position | Result List | Notes |
|------|----------|-------------|-------|
| `10 → 20 → 30` | 1 | `20 → 30` | Delete head (special case) |
| `10 → 20 → 30` | 2 | `10 → 30` | Delete middle — this code's case |
| `10 → 20 → 30` | 3 | `10 → 20` | Delete tail |
| `10` | 1 | `(empty)` | Single node — delete head |
| `10 → 20 → 30` | 5 | ⚠️ Crash | Position out of bounds |

---

## 🚨 Edge Cases to Handle

| Scenario | Problem | Fix |
|----------|---------|-----|
| `pos = 1` (delete head) | Loop doesn't run but `temp->next` is wrong — head itself must change | Handle separately: `head = head->next; delete temp;` |
| `pos > length` | `temp->next` becomes `NULL`, `delNode` is NULL — crash on `delete` | Add bounds check before loop |
| Empty list | `temp` is NULL — crash immediately | Add `if (head == NULL)` guard |

Robust version:

```cpp
// Delete head node
if (pos == 1) {
    Node* del = head;
    head = head->next;
    delete del;
    return 0;
}

// Traverse to pos - 1
Node* temp = head;
for (int i = 1; i < pos - 1 && temp != NULL; i++)
    temp = temp->next;

// Out of bounds check
if (temp == NULL || temp->next == NULL) {
    cout << "Position out of bounds." << endl;
    return 0;
}

Node* delNode = temp->next;
temp->next = delNode->next;
delete delNode;
```

---

## ⚖️ Comparison of Deletion Operations

| Operation | Time | Traversal Needed |
|-----------|------|-----------------|
| Delete from Beginning | O(1) | None — just move head |
| Delete from End | O(n) | Walk to second-to-last |
| **Delete at Position** ← you are here | O(n) | Walk to `pos - 1` |
| Delete by Value | O(n) | Walk until value matches |

---

## 🔗 Related Linked List Operations

| Operation | Time Complexity |
|-----------|----------------|
| Delete from Beginning | O(1) |
| Delete from End | O(n) |
| **Delete at Position** ← you are here | O(n) |
| Insert at Beginning | O(1) |
| Insert at End | O(n) |
| Insert at Position | O(n) |
| Search / Traverse | O(n) |

---

## 🏷️ Topic

Linked List → Deletion → Delete at Position

**Part of:** [Data_Structure_and_Algorithm](https://github.com/AnkitHaldar2006/Data_Structure_and_Algorithm)