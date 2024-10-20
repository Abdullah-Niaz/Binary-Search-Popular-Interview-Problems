#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(const vector<int>& nums, int target) {
        vector<int> result(2, -1); // Initialize result with [-1, -1]

        if (nums.empty()) return result; // Check for empty input

        // Find the first occurrence of target
        int first = findFirst(nums, target);
        // If target is not found, return [-1, -1]
        if (first == -1) return result;

        // Find the last occurrence of target
        int last = findLast(nums, target);

        result[0] = first; // Set the first occurrence index
        result[1] = last;  // Set the last occurrence index
        return result;     // Return the result
    }

private:
    int findFirst(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                // Check if this is the first occurrence
                if (mid == 0 || nums[mid - 1] != target) {
                    return mid;
                } else {
                    right = mid - 1; // Move left to find first occurrence
                }
            }
        }
        return -1; // Target not found
    }

    int findLast(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                // Check if this is the last occurrence
                if (mid == nums.size() - 1 || nums[mid + 1] != target) {
                    return mid;
                } else {
                    left = mid + 1; // Move right to find last occurrence
                }
            }
        }
        return -1; // Target not found
    }
};

int main() {
    Solution solution;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = solution.searchRange(nums, target);
    cout << "First and last positions of " << target << ": [" 
         << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
