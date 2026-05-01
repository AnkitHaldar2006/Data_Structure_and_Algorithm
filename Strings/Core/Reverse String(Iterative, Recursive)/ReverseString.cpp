#include <iostream>
#include <string>
using namespace std;

// Iterative method
string reverseIterative(string str) {
    int left = 0, right = str.length() - 1;
    while (left < right) {
        swap(str[left], str[right]);
        left++;
        right--;
    }
    return str;
}

// Recursive method
void reverseRecursive(string &str, int left, int right) {
    if (left >= right) return;
    swap(str[left], str[right]);
    reverseRecursive(str, left + 1, right - 1);
}

int main() {
    string str = "hello";

    cout << "Original: " << str << endl;

    cout << "Iterative Reverse: " << reverseIterative(str) << endl;

    reverseRecursive(str, 0, str.length() - 1);
    cout << "Recursive Reverse: " << str << endl;

    return 0;
}