# 🔃 Reverse a Linked List — Iterative — C++

> Flips every `next` pointer in the list to point backwards using three pointers — `prev`, `curr`, and `next` — reversing the entire chain in a single O(n) pass with O(1) space.

---

## 📌 What Does This Program Do?

This program **reverses a singly linked list in-place** using the classic three-pointer iterative technique. No extra array or stack is used — the existing nodes are rewired by flipping each `next` pointer one at a time as the algorithm walks forward.

```
Before:  head → [ 10 ] → [ 20 ] → [ 30 ] → NULL
After:   head → [ 30 ] → [ 20 ] → [ 10 ] → NULL
```

- **Time Complexity:** O(n) — visits every node exactly once
- **Space Complexity:** O(1) — no extra data structure, only three pointer variables

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

    Node* prev = NULL;   // Trails behind curr
    Node* curr = head;   // Currently being processed
    Node* next = NULL;   // Looks ahead to save the rest of the list

    while (curr != NULL) {
        next       = curr->next;   // Step 1: Save next node
        curr->next = prev;         // Step 2: Flip the pointer
        prev       = curr;         // Step 3: Advance prev
        curr       = next;         // Step 4: Advance curr
    }

    head = prev;  // prev is now the new head (last node of original list)

    // Print reversed list
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}
```

---

## ▶️ Output

```
Reversed list: 30 -> 20 -> 10 -> NULL
```

---

## 🧠 How It Works — Step by Step

```
List: 10 → 20 → 30 → NULL

Initial:
  prev = NULL
  curr = node(10)
  next = NULL

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Iteration 1  (curr = node(10))

  next       = curr->next  =  node(20)     ← save rest of list
  curr->next = prev        =  NULL          ← flip: 10 now points to NULL
  prev       = curr        =  node(10)
  curr       = next        =  node(20)

  NULL  ←  [ 10 ]    [ 20 ] → [ 30 ] → NULL
            ↑ prev    ↑ curr

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Iteration 2  (curr = node(20))

  next       = curr->next  =  node(30)     ← save rest of list
  curr->next = prev        =  node(10)      ← flip: 20 now points to 10
  prev       = curr        =  node(20)
  curr       = next        =  node(30)

  NULL ← [ 10 ] ← [ 20 ]    [ 30 ] → NULL
                   ↑ prev    ↑ curr

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Iteration 3  (curr = node(30))

  next       = curr->next  =  NULL          ← end of original list
  curr->next = prev        =  node(20)      ← flip: 30 now points to 20
  prev       = curr        =  node(30)
  curr       = next        =  NULL

  NULL ← [ 10 ] ← [ 20 ] ← [ 30 ]    NULL
                             ↑ prev    ↑ curr

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Loop exits (curr = NULL)

  head = prev = node(30)

  head → [ 30 ] → [ 20 ] → [ 10 ] → NULL   ✅
```

---

## 🗺️ Visual — Pointer State Per Iteration

```
Iter │  prev      │  curr      │  next      │  Link flipped
─────┼────────────┼────────────┼────────────┼──────────────────
 0   │  NULL      │  node(10)  │  —         │  (initial)
 1   │  node(10)  │  node(20)  │  node(20)  │  10 → NULL
 2   │  node(20)  │  node(30)  │  node(30)  │  20 → 10
 3   │  node(30)  │  NULL      │  NULL      │  30 → 20
end  │  node(30)  │  NULL      │  —         │  head = node(30)
```

---

## ⚙️ Code Breakdown

| Line | Description |
|------|-------------|
| `prev = NULL` | The reversed list starts empty — first node's `next` will point to NULL |
| `curr = head` | Start processing from the head of the original list |
| `next = curr->next` | Save the next node before the pointer is overwritten |
| `curr->next = prev` | **The flip** — reverses the arrow direction for this node |
| `prev = curr` | Slide `prev` forward — it now marks the new reversed list's head |
| `curr = next` | Slide `curr` forward — move on to the next node |
| `head = prev` | After loop, `prev` is the last node (new head) |

---

## 📊 Complexity Analysis

| Metric | Value | Reason |
|--------|-------|--------|
| Time | O(n) | Every node visited exactly once |
| Space | O(1) | Only `prev`, `curr`, `next` pointers — no stack or array |

> Compare with a recursive reversal which is also O(n) time but uses **O(n) call stack space** — the iterative approach is always preferred for memory-constrained environments.

---

## ⚠️ Why All Four Steps Are Required

```cpp
next       = curr->next;   // 🔒 MUST be first — saves the rest of list before it's lost
curr->next = prev;         // 🔁 The actual reversal — flips this node's pointer
prev       = curr;         // ⬅️  Slide prev forward
curr       = next;         // ➡️  Slide curr forward using the saved pointer
```

If `next = curr->next` is not saved **before** `curr->next = prev`, the rest of the list becomes permanently unreachable — a memory leak with no way to continue traversal.

---

## 🧪 Test Cases

| Input List | Reversed Output |
|------------|----------------|
| `10 → 20 → 30` | `30 → 20 → 10 → NULL` |
| `10 → 20 → 30 → 40` | `40 → 30 → 20 → 10 → NULL` |
| `10` (single node) | `10 → NULL` (unchanged) |
| `NULL` (empty) | `NULL` (loop never runs) |
| `10 → 20` | `20 → 10 → NULL` |

---

## 🚨 Edge Cases

| Scenario | Behaviour | Safe? |
|----------|-----------|-------|
| Empty list (`head = NULL`) | `curr = NULL` — loop never runs, `head = prev = NULL` | ✅ Safe |
| Single node | One iteration — `curr->next = NULL` (already was), `head = node` | ✅ Safe |
| Two nodes | Two iterations — both pointers flipped correctly | ✅ Safe |

---

## 🛠️ Real-World Applications

- **Palindrome check on linked list** — reverse second half, compare with first half
- **Undo operations** — reversal simulates unwinding a sequence of actions
- **Merge Sort** — reversing sub-lists during merge steps
- **Rotate a list** — reverse in segments to achieve rotation efficiently

---

## 🔗 Related Linked List Operations

| Operation | Time Complexity |
|-----------|----------------|
| **Reverse (Iterative)** ← you are here | O(n) — O(1) space |
| Reverse (Recursive) | O(n) — O(n) stack space |
| Find Middle (Slow & Fast) | O(n) |
| Traversal / Print | O(n) |
| Insert at Beginning | O(1) |
| Delete from Beginning | O(1) |

---

## 🏷️ Topic

Linked List → Reversal → Iterative Three-Pointer Technique

**Part of:** [Data_Structure_and_Algorithm](https://github.com/AnkitHaldar2006/Data_Structure_and_Algorithm)