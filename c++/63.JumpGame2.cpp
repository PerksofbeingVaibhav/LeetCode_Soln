/* 45. Jump Game II
You are given a 0-indexed array of integers nums of length n. You are initially
positioned at nums[0]. Each element nums[i] represents the maximum length of a
forward jump from index i. In other words, if you are at nums[i], you can jump
to any nums[i + j] where: 0 <= j <= nums[i] and i + j < n Return the minimum
number of jumps to reach nums[n - 1]. The test cases are generated such that you
can reach nums[n - 1].


Example 1:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1
step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [2,3,0,1,4]
Output: 2


Constraints:

1 <= nums.length <= 10^4
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].*/

// Approach:
// well see initialise a counter set to zero
// now when you are at ith index, access the ith element, jump to that index
// now repeat-> recursive approach
// at each jump increase counter by 1, check with the current index and
// nums.length()-1, if i==nums.length() return count else{repeat}

#include <vector>

using namespace std;

class Solution {
public:
  int jump(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return 0; // If there's only one element, no jumps are needed

    int jumps = 0;      // Count of jumps
    int farthest = 0;   // The farthest point we can reach with the next jump
    int currentEnd = 0; // The end of the current jump

    for (int i = 0; i < n - 1; ++i) {        // Iterate through the array
      farthest = max(farthest, i + nums[i]); // Update the farthest point

      if (i ==
          currentEnd) { // If we have reached the end of the current jump range
        jumps++;        // Increment the jump count
        currentEnd = farthest; // Move to the next jump range

        if (currentEnd >= n - 1) { // If we can reach the end, break
          break;
        }
      }
    }

    return jumps; // Return the total number of jumps
  }
};

int main() {
  Solution sol;

  // Test Case 1
  vector<int> nums1 = {2, 3, 1, 1, 4};
  cout << "Output: " << sol.jump(nums1) << " | Expected: 2" << endl;

  // Test Case 2
  vector<int> nums2 = {2, 3, 0, 1, 4};
  cout << "Output: " << sol.jump(nums2) << " | Expected: 2" << endl;

  // Test Case 3
  vector<int> nums3 = {0};
  cout << "Output: " << sol.jump(nums3) << " | Expected: 0" << endl;

  // Test Case 4
  vector<int> nums4 = {2, 1};
  cout << "Output: " << sol.jump(nums4) << " | Expected: 1" << endl;

  // Test Case 5
  vector<int> nums5 = {3, 2, 1, 0, 4};
  cout << "Output: " << sol.jump(nums5) << " | Expected: 2" << endl;

  // Test Case 6
  vector<int> nums6 = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  cout << "Output: " << sol.jump(nums6) << " | Expected: 1" << endl;

  // Test Case 7
  vector<int> nums7 = {1, 1, 1, 1, 1};
  cout << "Output: " << sol.jump(nums7) << " | Expected: 4" << endl;

  // Test Case 8
  vector<int> nums8 = {3, 2, 1, 0, 4};
  cout << "Output: ";
  int res = sol.jump(nums8);
  if (res == -1)
    cout << "Cannot reach the end | Expected: Cannot reach the end" << endl;
  else
    cout << res << " | Expected: Cannot reach the end" << endl;

  return 0;
}

//- Time complexity:O(n)

//- Space complexity:O(1)
