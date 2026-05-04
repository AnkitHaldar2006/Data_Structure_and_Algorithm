#include <iostream>
using namespace std;

class Node8 {
public:
    int data;
    Node8* next;
    Node8(int val) { data = val; next = NULL; }
};

int main8() {
    Node8* head = new Node8(10);
    head->next = new Node8(20);
    head->next->next = new Node8(30);
    head->next->next->next = new Node8(40);

    Node8* slow = head;
    Node8* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle element: " << slow->data << endl;
    return 0;
}
