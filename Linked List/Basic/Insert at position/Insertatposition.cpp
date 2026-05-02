#include <iostream>
using namespace std;

class Node3 {
public:
    int data;
    Node3* next;
    Node3(int val) { data = val; next = NULL; }
};

int main3() {
    Node3* head = new Node3(10);
    head->next = new Node3(20);

    int pos = 2, val = 15;
    Node3* newNode = new Node3(val);

    Node3* temp = head;
    for (int i = 1; i < pos - 1; i++) temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Inserted at position" << endl;
    return 0;
}