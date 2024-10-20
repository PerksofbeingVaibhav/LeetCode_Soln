# 3Sum
# Description: Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that:

# i != j
# i != k
# j != k
# nums[i] + nums[j] + nums[k] == 0
# Notice that the solution set must not contain duplicate triplets.

# Example:

# Input: nums = [-1, 0, 1, 2, -1, -4]

# Output: [[-1, -1, 2], [-1, 0, 1]]

# #Constraints:
# 0 <= nums.length <= 3000
# -10^5 <= nums[i] <= 10^5

def threeSum(nums):
    nums.sort()  # Sort the array
    triplets = []
    
    for i in range(len(nums) - 2):
        # Skip duplicates for the first element
        if i > 0 and nums[i] == nums[i - 1]:
            continue
        
        left, right = i + 1, len(nums) - 1
        
        while left < right:
            current_sum = nums[i] + nums[left] + nums[right]
            
            if current_sum < 0:
                left += 1  # Move the left pointer to the right to increase the sum
            elif current_sum > 0:
                right -= 1  # Move the right pointer to the left to decrease the sum
            else:
                # Found a triplet
                triplets.append([nums[i], nums[left], nums[right]])
                
                while left < right and nums[left] == nums[left + 1]:
                    left += 1
                
                while left < right and nums[right] == nums[right - 1]:
                    right -= 1
                left += 1
                right -= 1

    return triplets

nums = [-1, 0, 1, 2, -1, -4]
print(threeSum(nums))
