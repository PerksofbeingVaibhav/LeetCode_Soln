/*
213. House Robber II

You are a professional robber planning to rob houses along a street. Each house
has a certain amount of money stashed. All houses at this place are arranged in
a circle. That means the first house is the neighbor of the last one. Meanwhile,
adjacent houses have a security system connected, and it will automatically
contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house,
return the maximum amount of money you can rob tonight without alerting the
police.

Example 1:
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money =
2), because they are adjacent houses.

Example 2:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 3:
Input: nums = [1,2,3]
Output: 3

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000
*/

// Well I though to maximise i=i+2,j=j+2; return max(i,j)
// but the thing is 0th,last are neighbour so it actually is wrong for odd
// length array house are in circular fashion

// circular array, maximise sum
// well the logic we thought is correcct for nums.size()%2==0
// but for nums.size()%2==1
// what if i do like i=1 to size-2 and add max(0,size)

// broke approach
/*
class Solution {
public:
    int rob(vector<int>& nums) {
        //even length house
        if(nums.size()%2==0){
            int oddSum=0, evenSum=0;
            for(int i = 0; i < nums.size(); i += 2){
                oddSum+=nums[i];
            }
            for(int i = 1; i < nums.size(); i += 2) {
                evenSum+=nums[i];
            }
            return max(oddSum,evenSum);
        }
        //odd length house
        else{
            int evenSum=0;

            for(int i = 1; i < nums.size(); i += 2) {
                evenSum+=nums[i];
            }
            int x=max(nums[0],nums[nums.size()]);
            return max(evenSum,x);
        }
    }
};
*/

// Optimised Approach:
/*
Dynamic Programming Array (dp):
dp[i] represents the maximum money that can be robbed up to house i.
For each house i, you can either:
Rob house i and add its value to dp[i-2] (because you can't rob two adjacent
houses). Skip house i and keep the value dp[i-1] (the maximum money robbed up to
the previous house).

Base Cases:
If there's only one house, rob it (nums[0]).
If there are two houses, rob the one with the most money (max(nums[0],
nums[1])).
*/

#include <vector>
using namespace std;

class Solution {
public:
  int robRange(vector<int> &nums, int start, int end) {
    int prev2 = 0, prev1 = 0;

    for (int i = start; i <= end; i++) {
      int curr = max(prev1, prev2 + nums[i]);
      prev2 = prev1;
      prev1 = curr;
    }

    return prev1;
  }

  int rob(vector<int> &nums) {
    int n = nums.size();

    // Handle base cases
    if (n == 1)
      return nums[0];
    if (n == 2)
      return max(nums[0], nums[1]);

    // Either rob houses 0 to n-2, or houses 1 to n-1
    return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
  }
};

int main() {
  Solution solution;

  // Test case 1
  vector<int> nums1 = {2, 3, 2};
  cout << "Test case 1 - Expected: 3, Output: " << solution.rob(nums1) << endl;

  // Test case 2
  vector<int> nums2 = {1, 2, 3, 1};
  cout << "Test case 2 - Expected: 4, Output: " << solution.rob(nums2) << endl;

  // Test case 3
  vector<int> nums3 = {1, 2, 3};
  cout << "Test case 3 - Expected: 3, Output: " << solution.rob(nums3) << endl;

  return 0;
}
