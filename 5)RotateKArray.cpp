#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; 
    if (k == 0) return;

    // Reverse the entire array
    reverse(nums.begin(), nums.end());
    // Reverse the first k elements
    reverse(nums.begin(), nums.begin() + k);
    // Reverse the elements from k to the end
    reverse(nums.begin() + k, nums.end());
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    rotate(nums, k);

    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
