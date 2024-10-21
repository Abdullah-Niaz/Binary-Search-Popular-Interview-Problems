#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> charSet; // Set to store unique characters
        int left = 0;                // Left pointer for sliding window
        int res = 0;                 // To store the length of the longest substring

        // Iterate through the string with the right pointer
        for (int right = 0; right < s.size(); ++right)
        {
            // If the character is already in the set, shrink the window
            while (charSet.find(s[right]) != charSet.end())
            {
                charSet.erase(s[left]); // Remove the character at the left pointer
                ++left;                 // Move the left pointer to the right
            }
            charSet.insert(s[right]); // Add the current character to the set

            // Calculate the length of the current window and update the result
            res = max(res, right - left + 1);
        }

        return res; // Return the length of the longest substring without repeating characters
    }
};

int main()
{
    Solution solution;
    string s = "abcabcbb";
    cout << solution.lengthOfLongestSubstring(s) << endl; // Output: 3
    return 0;
}
