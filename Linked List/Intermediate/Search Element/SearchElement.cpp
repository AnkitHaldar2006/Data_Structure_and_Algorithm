#include <iostream>
using namespace std;

class Node10 {
public:
    int data;
    Node10* next;
    Node10(int val) { data = val; next = NULL; }
};

int main10() {
    Node10* head = new Node10(10);
    head->next = new Node10(20);
    head->next->next = new Node10(30);

    int key = 20;
    Node10* temp = head;
    int position = 1;
    bool found = false;

    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Element found at position: " << position << endl;
            found = true;
            break;
        }
        temp = temp->next;
        position++;
    }

    if (!found) cout << "Element not found" << endl;

    return 0;
}

