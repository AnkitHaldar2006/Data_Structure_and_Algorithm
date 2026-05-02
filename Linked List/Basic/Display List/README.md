![Linked List Traversal Banner](banner.svg)

# 🔍 Linked List Traversal — C++

> The most fundamental linked list operation — visits every node exactly once from head to NULL, printing each value along the way in O(n) time.

---

## 📌 What Does This Program Do?

This program **builds a singly linked list** and then **traverses** it from head to tail, printing the value of each node in the classic arrow format used to visualize linked lists.

```
Output:  10 -> 20 -> 30 -> NULL
```

Traversal is the backbone of almost every other linked list operation — searching, counting, printing, and deletion all rely on the same pattern.

- **Time Complexity:** O(n) — visits every node exactly once
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
    // Build list: 10 → 20 → 30 → NULL
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    // Traverse and print
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;         // Move to next node
    }
    cout << "NULL" << endl;

    return 0;
}
```

---

## ▶️ Output

```
10 -> 20 -> 30 -> NULL
```

---

## 🧠 How It Works — Step by Step

```
List: head → [ 10 ] → [ 20 ] → [ 30 ] → NULL

  Iteration 1:
    temp = node(10)  →  temp != NULL ✅  →  print "10 -> "  →  temp = node(20)

  Iteration 2:
    temp = node(20)  →  temp != NULL ✅  →  print "20 -> "  →  temp = node(30)

  Iteration 3:
    temp = node(30)  →  temp != NULL ✅  →  print "30 -> "  →  temp = NULL

  Iteration 4:
    temp = NULL      →  temp != NULL ❌  →  loop exits

  Print "NULL"

  Final output: 10 -> 20 -> 30 -> NULL  ✅
```

---

## ⚙️ Code Breakdown

| Line | Description |
|------|-------------|
| `Node* head = new Node(10)` | Creates first node on the heap — head points to it |
| `head->next = new Node(20)` | Links second node to first |
| `head->next->next = new Node(30)` | Links third node to second |
| `Node* temp = head` | Traversal pointer — starts at head, **never** moves `head` itself |
| `while (temp != NULL)` | Loop continues as long as there's a valid node to visit |
| `cout << temp->data << " -> "` | Prints the current node's value |
| `temp = temp->next` | Advances to the next node in the list |
| `cout << "NULL"` | Marks the end of the list visually |

---

## 📊 Complexity Analysis

| Metric | Value | Reason |
|--------|-------|--------|
| Time | O(n) | Every node is visited exactly once |
| Space | O(1) | Only the `temp` pointer is used — no extra memory |

---

## 🗺️ Visual — Node Structure & Traversal

```
Memory layout:

  ┌────────────┐     ┌────────────┐     ┌────────────┐
  │  data = 10 │     │  data = 20 │     │  data = 30 │
  │  next ─────│────→│  next ─────│────→│  next=NULL │
  └────────────┘     └────────────┘     └────────────┘
   ↑ head / temp[0]   ↑ temp[1]          ↑ temp[2]

Traversal pointer moves:
  temp → node(10) → node(20) → node(30) → NULL → STOP
```

---

## 🔑 Why Use `temp` Instead of Moving `head`?

```cpp
// ✅ CORRECT — use a separate pointer
Node* temp = head;
while (temp != NULL) { ... temp = temp->next; }
// head still points to node(10) after the loop ✅

// ❌ WRONG — moving head directly
while (head != NULL) { ... head = head->next; }
// head is now NULL after the loop — the entire list is lost! ❌
```

Always traverse with a **copy** of the head pointer. Moving `head` itself destroys the only reference to the list.

---

## 🧪 Test Cases

| List | Output |
|------|--------|
| `10 → 20 → 30` | `10 -> 20 -> 30 -> NULL` |
| `42` (single node) | `42 -> NULL` |
| `1 → 2 → 3 → 4 → 5` | `1 -> 2 -> 3 -> 4 -> 5 -> NULL` |
| `(empty, head = NULL)` | `NULL` (loop never runs) |

---

## 🚨 Edge Cases to Handle

| Scenario | Behaviour | Safe? |
|----------|-----------|-------|
| Empty list (`head == NULL`) | `temp = NULL` — `while` condition is false immediately — prints `NULL` | ✅ Safe |
| Single node | Loop runs once, prints value, then `temp = NULL`, loop exits | ✅ Safe |
| Very long list | Works correctly — O(n) visits | ✅ Safe |

---

## 🛠️ Common Traversal Patterns Built on This

| Task | What Changes |
|------|-------------|
| **Count nodes** | Replace `cout` with `count++` |
| **Find a value** | Replace `cout` with `if (temp->data == key) return temp` |
| **Sum all values** | Replace `cout` with `sum += temp->data` |
| **Find max/min** | Replace `cout` with `if (temp->data > max) max = temp->data` |
| **Copy a list** | Create a new node for each `temp->data` visited |

Traversal is the single most reused pattern in all linked list problems.

---

## 🔗 Related Linked List Operations

| Operation | Time Complexity |
|-----------|----------------|
| **Traversal / Print** ← you are here | O(n) |
| Insert at Beginning | O(1) |
| Insert at End | O(n) |
| Delete from Beginning | O(1) |
| Delete from End | O(n) |
| Delete at Position | O(n) |
| Search by Value | O(n) |

---

## 🏷️ Topic

Linked List → Fundamentals → Traversal & Printing

**Part of:** [Data_Structure_and_Algorithm](https://github.com/AnkitHaldar2006/Data_Structure_and_Algorithm)