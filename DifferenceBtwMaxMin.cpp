#include <iostream>
#include <vector>
#include <climits> // for INT_MIN, INT_MAX

using namespace std;

int maxDifference(vector<int>& nums) {
    if (nums.size() < 2) {
        return 0; 
    }

    int minElement = nums[0];
    int maxDiff = INT_MIN;

    for (int i = 1; i < nums.size(); ++i) {
        // Update minElement
        if (nums[i] < minElement) {
            minElement = nums[i];
        }

        // Calculate current difference and update maxDiff
        int currentDiff = nums[i] - minElement;
        if (currentDiff > maxDiff) {
            maxDiff = currentDiff;
        }
    }

    return maxDiff;
}

int main() {
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    
    int result = maxDifference(nums);
    
    cout << "Maximum difference between any two elements in the array: " << result << endl;

    return 0;
}
