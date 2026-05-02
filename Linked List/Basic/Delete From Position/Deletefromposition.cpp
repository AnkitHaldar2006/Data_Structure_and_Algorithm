#include <iostream>
using namespace std;

class Node6 {
public:
    int data;
    Node6* next;
    Node6(int val) { data = val; next = NULL; }
};

int main6() {
    Node6* head = new Node6(10);
    head->next = new Node6(20);
    head->next->next = new Node6(30);

    int pos = 2;
    Node6* temp = head;

    for (int i = 1; i < pos - 1; i++) temp = temp->next;

    Node6* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;

    cout << "Deleted from position" << endl;
    return 0;
}
