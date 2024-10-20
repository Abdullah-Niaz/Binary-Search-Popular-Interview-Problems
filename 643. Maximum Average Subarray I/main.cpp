#include <iostream>
#include <vector>
#include <algorithm> // for max()

using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    // Calculate the sum of the first 'k' elements
    double current_sum = 0;
    for (int i = 0; i < k; ++i) {
        current_sum += nums[i];
    }

    // Initialize max_sum to current_sum
    double max_sum = current_sum;

    // Slide the window across the array
    for (int i = k; i < nums.size(); ++i) {
        current_sum += nums[i] - nums[i - k]; // slide window
        max_sum = max(max_sum, current_sum);  // update max_sum
    }

    // Return the maximum average
    return max_sum / k;
}

int main() {
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    double result = findMaxAverage(nums, k);
    cout << "Maximum average: " << result << endl;

    return 0;
}
