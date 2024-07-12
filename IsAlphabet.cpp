#include <iostream>
#include <cctype> // for std::isalpha

using namespace std;

bool containsOnlyAlphabetic(string str) {
    for (char c : str) {
        if (!isalpha(c)) {
            return false; // Found a non-alphabetic character
        }
    }
    return true; // All characters are alphabetic
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    if (containsOnlyAlphabetic(input)) {
        cout << "The string contains only alphabetic characters." << endl;
    } else {
        cout << "The string contains non-alphabetic characters." << endl;
    }

    return 0;
}
