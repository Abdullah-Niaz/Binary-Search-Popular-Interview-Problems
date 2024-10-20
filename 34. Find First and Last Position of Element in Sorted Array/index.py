class Solution:
    def searchRange(self, nums, target):
        result = [-1, -1]  # Initialize result with [-1, -1]

        if not nums:  # Check for empty input
            return result

        # Find the first occurrence of target
        first = self.findFirst(nums, target)
        # If target is not found, return [-1, -1]
        if first == -1:
            return result

        # Find the last occurrence of target
        last = self.findLast(nums, target)

        result[0] = first  # Set the first occurrence index
        result[1] = last   # Set the last occurrence index
        return result      # Return the result

    def findFirst(self, nums, target):
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid - 1
            else:
                # Check if this is the first occurrence
                if mid == 0 or nums[mid - 1] != target:
                    return mid
                else:
                    right = mid - 1  # Move left to find first occurrence
        return -1  # Target not found

    def findLast(self, nums, target):
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid - 1
            else:
                # Check if this is the last occurrence
                if mid == len(nums) - 1 or nums[mid + 1] != target:
                    return mid
                else:
                    left = mid + 1  # Move right to find last occurrence
        return -1  # Target not found


if __name__ == "__main__":
    solution = Solution()
    nums = [5, 7, 7, 8, 8, 10]
    target = 8

    result = solution.searchRange(nums, target)
    print(f"First and last positions of {target}: {result}")
