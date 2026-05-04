# 🐢🐇 Find Middle of Linked List — C++

> Uses Floyd's Slow & Fast Pointer technique to find the middle node in a **single pass** — no length calculation, no second traversal, just two pointers moving at different speeds.

---

## 📌 What Does This Program Do?

This program finds the **middle node** of a singly linked list using the classic **Slow & Fast Pointer** (Tortoise and Hare) technique. The fast pointer moves two steps at a time while the slow pointer moves one. When fast reaches the end, slow is exactly at the middle.

```
List:    head → [ 10 ] → [ 20 ] → [ 30 ] → [ 40 ] → NULL
Middle:  30   (second middle for even-length list)
```

- **Time Complexity:** O(n) — single pass through the list
- **Space Complexity:** O(1) — only two pointer variables used
- **Technique:** Floyd's Slow & Fast Pointer (Tortoise and Hare)

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
    // Build list: 10 → 20 → 30 → 40 → NULL
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    Node* slow = head;   // 🐢 moves 1 step at a time
    Node* fast = head;   // 🐇 moves 2 steps at a time

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;         // 1 step
        fast = fast->next->next;   // 2 steps
    }

    cout << "Middle element: " << slow->data << endl;
    return 0;
}
```

---

## ▶️ Output

```
Middle element: 30
```

---

## 🧠 How It Works — Step by Step

```
List: 10 → 20 → 30 → 40 → NULL   (4 nodes)

Initial:
  slow = node(10)   🐢
  fast = node(10)   🐇

  [ 10 ] → [ 20 ] → [ 30 ] → [ 40 ] → NULL
    ↑ slow
    ↑ fast

─────────────────────────────────────────────
Iteration 1:
  fast != NULL ✅   fast->next = node(20) != NULL ✅  →  continue
  slow = slow->next       →  node(20)   🐢
  fast = fast->next->next →  node(30)   🐇

  [ 10 ] → [ 20 ] → [ 30 ] → [ 40 ] → NULL
             ↑ slow   ↑ fast

─────────────────────────────────────────────
Iteration 2:
  fast != NULL ✅   fast->next = node(40) != NULL ✅  →  continue
  slow = slow->next       →  node(30)   🐢
  fast = fast->next->next →  NULL       🐇

  [ 10 ] → [ 20 ] → [ 30 ] → [ 40 ] → NULL
                      ↑ slow            ↑ fast = NULL

─────────────────────────────────────────────
Iteration 3:
  fast = NULL  ❌  →  loop exits

  slow = node(30)  →  Middle = 30  ✅
```

---

## 🗺️ Visual — Pointer Positions Per Iteration

```
Step  │  slow      │  fast      │  slow->data
──────┼────────────┼────────────┼────────────
 0    │  node(10)  │  node(10)  │  10
 1    │  node(20)  │  node(30)  │  20
 2    │  node(30)  │  NULL      │  30  ← middle ✅
```

---

## ⚙️ Code Breakdown

| Line | Description |
|------|-------------|
| `Node* slow = head` | 🐢 Slow pointer — advances 1 node per iteration |
| `Node* fast = head` | 🐇 Fast pointer — advances 2 nodes per iteration |
| `fast != NULL` | Guards against fast reaching end (odd-length lists) |
| `fast->next != NULL` | Guards against fast->next->next crashing (even-length lists) |
| `slow = slow->next` | Turtle takes 1 step |
| `fast = fast->next->next` | Hare takes 2 steps |
| `slow->data` | When fast stops, slow is at the middle node |

---

## 📊 Complexity Analysis

| Metric | Value | Reason |
|--------|-------|--------|
| Time | O(n) | fast travels the full list in n/2 iterations — slow follows at half speed |
| Space | O(1) | Only two pointer variables regardless of list size |

> **Compare to naive approach:** Find length first (O(n)), then traverse to `length/2` (O(n)) = O(2n). The slow & fast pointer does it in **one pass** = O(n/2) iterations.

---

## 🔍 Why Two Conditions in the Loop?

```cpp
while (fast != NULL && fast->next != NULL)
```

| Condition | Protects Against |
|-----------|-----------------|
| `fast != NULL` | Odd-length list — fast lands exactly on NULL after the last node |
| `fast->next != NULL` | Even-length list — fast is at last node, `fast->next->next` would crash |

Both conditions are required. Removing either one causes a NULL dereference crash on certain list lengths.

---

## 🧪 Test Cases — Odd vs Even Length

| List | Length | Middle Node | Output |
|------|--------|-------------|--------|
| `10 → 20 → 30` | 3 (odd) | node(20) | `20` — exact middle |
| `10 → 20 → 30 → 40` | 4 (even) | node(30) | `30` — second middle |
| `10 → 20 → 30 → 40 → 50` | 5 (odd) | node(30) | `30` — exact middle |
| `10 → 20` | 2 (even) | node(20) | `20` — second middle |
| `10` | 1 | node(10) | `10` — only node |

> For even-length lists this implementation returns the **second middle** node. To get the first middle, stop when `fast->next->next == NULL` instead.

---

## 🔁 Odd vs Even — Why Different Middles?

```
Odd (3 nodes):             Even (4 nodes):
  10 → 20 → 30              10 → 20 → 30 → 40

  slow stops at 20 ✅        slow stops at 30 (second middle)
  (exact centre)             (first middle would be 20)
```

This is expected behaviour — for even-length lists there is no single exact middle, so the algorithm picks the second one by default.

---

## 🛠️ Real-World Applications

- **Merge Sort on Linked List** — split the list at the middle node to divide it into two halves
- **Palindrome Check** — find the middle, reverse the second half, compare with the first
- **Cycle Detection** — the same slow & fast pointer concept detects loops (Floyd's Cycle Detection Algorithm)
- **Reorder List** — split at middle, reverse second half, then interleave

---

## 🔗 Related Linked List Operations

| Operation | Time Complexity |
|-----------|----------------|
| **Find Middle (Slow & Fast)** ← you are here | O(n) |
| Traversal / Print | O(n) |
| Insert at Beginning | O(1) |
| Delete from Beginning | O(1) |
| Insert / Delete at End | O(n) |
| Reverse a Linked List | O(n) |

---

## 🏷️ Topic

Linked List → Two Pointer → Slow & Fast Pointer → Find Middle

**Part of:** [Data_Structure_and_Algorithm](https://github.com/AnkitHaldar2006/Data_Structure_and_Algorithm)








