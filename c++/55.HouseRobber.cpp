/*
198. House Robber

You are a professional robber planning to rob houses along a street. Each house
has a certain amount of money stashed, the only constraint stopping you from
robbing each of them is that adjacent houses have security systems connected and
it will automatically contact the police if two adjacent houses were broken into
on the same night.

Given an integer array nums representing the amount of money of each house,
return the maximum amount of money you can rob tonight without alerting the
police.

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5
(money = 1). Total amount you can rob = 2 + 9 + 1 = 12.


Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 400
*/

// Approach:
// can't break into 2 adjacent houses
// maximise the amount
// what we can do is that initialise a int odd, even
// put sum of odd houses into odd, sum of even houses into even
// return max(odd,even)

/*
class Solution {
public:
  int rob(vector<int> &nums) {
    int even = 0;
    int odd = 0;

    // Iterate over even indices
    for (int i = 0; i < nums.size(); i += 2) {  // Use i += 2 to move by 2
      even += nums[i];
    }

    // Iterate over odd indices
    for (int i = 1; i < nums.size(); i += 2) {  // Use i += 2 to move by 2
      odd += nums[i];
    }

    // Return the maximum sum of even or odd indices
    return max(even, odd);
  }
};
*/
// now now, wrong ans for [2,1,1,2] -> 4 is ans, but 3 is outcome
/*maximum money at previous house
vs
maximum money at current house + i - 2 house

max(index 3, index 4 + index 2 + index 0)
= max(11, 1 + 11)
= 12

The first 11 is maximum money from [2,7,9,3].
The second 11 comes from index 2(= 9) + index 0(= 2).
So, 1 + 11 means you break index 0, index 2 and index 4 houses.

*/

// O(n) solution
// the base cases are initialized:

// dp[0] stores the maximum amount if only the first house is considered.
// dp[1] stores the maximum amount if the robber either robs the first or the
// second house, whichever gives more money.

// loop->
// rob the i-th house and add its loot to the maximum amount that could be
// accumulated until two houses before (nums[i] + dp[i-2]). skip the i-th house
// and take the maximum amount that could be accumulated until the previous
// house (dp[i-1]). the maximum of these two options is stored in dp[i].

/*
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        vector<int> dp(n, 0);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        return dp[n - 1];
    }
};
*/
/*
class Solution:
def rob(self, nums: List[int]) → int:
prev_rob = max_rob = 0
for cur_val in nums:
temp = max(max_rob, prev_rob + cur_val)
prev_rob = max_rob
max_rob = temp
return max_ rob
*/
class Solution {
public:
  int rob(vector<int> &nums) {
    int prev_rob = 0;
    int max_rob = 0;

    for (int i = 0; i < nums.size(); i++) {
      int temp = max(max_rob, prev_rob + nums[i]);
      prev_rob = max_rob;
      max_rob = temp;
    }
    return max_rob;
  }
};
