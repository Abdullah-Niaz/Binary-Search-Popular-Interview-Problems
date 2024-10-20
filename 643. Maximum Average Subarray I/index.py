def findMaxAverage(nums, k):
    # Calculate the sum of the first 'k' elements
    current_sum = sum(nums[:k])
    max_sum = current_sum

    # Slide the window over the array
    for i in range(k, len(nums)):
        current_sum += nums[i] - nums[i - k]
        max_sum = max(max_sum, current_sum)

    # Return the maximum average
    return max_sum / k


# Example usage
nums = [1, 12, -5, -6, 50, 3]
k = 4
result = findMaxAverage(nums, k)
print(f"Maximum average: {result:.5f}")
