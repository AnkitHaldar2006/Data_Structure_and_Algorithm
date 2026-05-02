#include <iostream>
using namespace std;

class Node2 {
public:
    int data;
    Node2* next;
    Node2(int val) { data = val; next = NULL; }
};

int main2() {
    Node2* head = new Node2(10);

    Node2* newNode = new Node2(20);
    Node2* temp = head;

    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;

    cout << "Inserted at end" << endl;
    return 0;
}