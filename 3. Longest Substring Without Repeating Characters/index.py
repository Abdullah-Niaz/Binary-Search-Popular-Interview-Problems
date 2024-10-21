class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        charSet = set()  # To store the characters of the current substring
        left = 0         # Left pointer for the sliding window
        res = 0          # Result to store the length of the longest substring

        # Right pointer moves through each character in the string
        for right in range(len(s)):
            # If the current character is already in the set, shrink the window
            while s[right] in charSet:
                # Remove the character at the left pointer
                charSet.remove(s[left])
                # Move the left pointer to the right (shrink window)
                left += 1

            # Add the current character to the set
            charSet.add(s[right])

            # Update the result with the maximum length found
            res = max(res, right - left + 1)

        return res  # Return the length of the longest substring without repeating characters

 
solution = Solution()
s = "abcabcbb"
print(solution.lengthOfLongestSubstring(s))  # Output: 3
