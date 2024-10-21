/*
377. Combination Sum IV

Given an array of distinct integers nums and a target integer target, return the
number of possible combinations that add up to target. The test cases are
generated so that the answer can fit in a 32-bit integer.

Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.

Example 2:

Input: nums = [9], target = 3
Output: 0

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 1000
All the elements of nums are unique.
1 <= target <= 1000
*/

// Approach:
/*
so what we actually want to do
given an array 'nums', we need to return all combination 'target' can be made
such that all elements of 'nums' are covered.

target can't be less than 0
for target = 0; return 1{as only 0 can return 0}
initialise a target=0, then add the no into them

initialise a vector<int> dp with memoization for array and target

create a dp array where dp[i] represent no of ways to make i from nums
since target=0-> dp[0]=1


add the arrayElements using for loop, for each iteration update the dp table.
return ans
*/

// Explanation
/*
Initialize dp: We create a dp array where dp[i] will store the number of ways to
make i using the elements of nums. dp[0] = 1 because there's exactly one way to
make 0 — by using no numbers at all.

Loop through target values: For each target value i, iterate over every element
of nums. If i is greater than or equal to num, we update dp[i] by adding dp[i -
num] to it.

Return the result: The value dp[target] gives us the number of combinations that
sum up to target.
*/

#include <vector>

using namespace std;

class Solution {
public:
  long long combinationSum4(vector<int> &nums, int target) {
    // Initialize the dp array with size (target + 1) and set dp[0] = 1.
    vector<long long> dp(target + 1, 0);
    dp[0] = 1;

    // Iterate through all target values and compute combinations.
    for (int i = 1; i <= target; i++) {
      for (int num : nums) {
        if (i >= num) {
          dp[i] +=
              dp[i - num]; // Add the number of ways to form (i - num) to dp[i].
        }
      }
    }

    return dp[target];
  }
};

int main() {
  vector<int> nums = {1, 2, 3};
  int target = 4;
  cout << "Number of combinations: " << combinationSum4(nums, target) << endl;

  return 0;
}

// Time complexity:O(target*n)

// Space complexity:O(target)
