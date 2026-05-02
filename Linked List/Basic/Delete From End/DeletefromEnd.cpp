#include <iostream>
using namespace std;

class Node5 {
public:
    int data;
    Node5* next;
    Node5(int val) { data = val; next = NULL; }
};

int main5() {
    Node5* head = new Node5(10);
    head->next = new Node5(20);

    Node5* temp = head;
    while (temp->next->next != NULL) temp = temp->next;

    delete temp->next;
    temp->next = NULL;

    cout << "Deleted from end" << endl;
    return 0;
}
