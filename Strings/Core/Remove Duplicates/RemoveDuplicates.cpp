#include <iostream>
#include <unordered_set>
using namespace std;

string removeDuplicates(string str) {
    unordered_set<char> seen;
    string result = "";

    for (char c : str) {
        if (seen.find(c) == seen.end()) {
            result += c;
            seen.insert(c);
        }
    }
    return result;
}

int main() {
    string str = "programming";

    cout << "After removing duplicates: " 
         << removeDuplicates(str) << endl;

    return 0;
}