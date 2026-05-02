#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) { data = val; next = NULL; }
};

int main() {
    Node* head = NULL;

    int val = 10;
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;

    cout << "Inserted at beginning: " << head->data << endl;
    return 0;
}