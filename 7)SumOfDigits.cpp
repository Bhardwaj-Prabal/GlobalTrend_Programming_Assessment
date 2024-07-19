#include <iostream>

using namespace std;

int sumOfDigits(int number) {
    int sum = 0;
    
    // Handle negative numbers by taking absolute value
    number = abs(number);

    while (number > 0) {
        sum += number % 10;  // Add the last digit to the sum
        number /= 10;        // Remove the last digit from number
    }

    return sum;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int sum = sumOfDigits(num);

    cout << "Sum of digits of " << num << " is " << sum << endl;

    return 0;
}
