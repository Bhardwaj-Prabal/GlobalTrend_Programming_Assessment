#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndexMap;
    int maxLength = 0;
    int start = 0;  // Start index of the current window

    for (int end = 0; end < s.length(); ++end) {
        char currentChar = s[end];

        // If the character is already in the map and its index is within the current window
        if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= start) {
            start = charIndexMap[currentChar] + 1;  // Move the start to the right of the previous occurrence
        }

        charIndexMap[currentChar] = end;  
        maxLength = max(maxLength, end - start + 1);  // Calculate the maximum length
    }

    return maxLength;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int length = lengthOfLongestSubstring(s);
    cout << "The length of the longest substring without repeating characters is: " << length << endl;

    return 0;
}
