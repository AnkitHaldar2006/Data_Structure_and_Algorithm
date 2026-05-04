#include <iostream>
using namespace std;

class Node9 {
public:
    int data;
    Node9* next;
    Node9(int val) { data = val; next = NULL; }
};

int main9() {
    Node9* head = new Node9(10);
    head->next = new Node9(20);
    head->next->next = new Node9(30);

    Node9* prev = NULL;
    Node9* curr = head;
    Node9* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;

    cout << "Reversed list: ";
    Node9* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}
