#include <iostream>
using namespace std;

void countCharacters(string str) {
    int vowels = 0, consonants = 0, digits = 0, spaces = 0;

    for (char c : str) {
        if (isalpha(c)) {
            char lower = tolower(c);
            if (lower == 'a' || lower == 'e' || lower == 'i' || 
                lower == 'o' || lower == 'u')
                vowels++;
            else
                consonants++;
        }
        else if (isdigit(c))
            digits++;
        else if (isspace(c))
            spaces++;
    }

    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
    cout << "Digits: " << digits << endl;
    cout << "Spaces: " << spaces << endl;
}

int main() {
    string str = "Hello World 123";

    countCharacters(str);

    return 0;
}