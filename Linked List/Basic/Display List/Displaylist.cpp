#include <iostream>
using namespace std;

class Node7 {
public:
    int data;
    Node7* next;
    Node7(int val) { data = val; next = NULL; }
};

int main7() {
    Node7* head = new Node7(10);
    head->next = new Node7(20);
    head->next->next = new Node7(30);

    Node7* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}
