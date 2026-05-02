#include <iostream>
using namespace std;

class Node4 {
public:
    int data;
    Node4* next;
    Node4(int val) { data = val; next = NULL; }
};

int main4() {
    Node4* head = new Node4(10);
    head->next = new Node4(20);

    Node4* temp = head;
    head = head->next;
    delete temp;

    cout << "Deleted from beginning" << endl;
    return 0;