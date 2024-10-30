/* 55. Jump Game

You are given an integer array nums. You are initially positioned at the array's
first index, and each element in the array represents your maximum jump length
at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump
length is 0, which makes it impossible to reach the last index.

Constraints:

1 <= nums.length <= 10^4
0 <= nums[i] <= 10^5
*/

// well first of all we are always at 0th
// access 0+a[0] element
// now access a[0+a[0]] element
// and check at each iteration if it's equal to arr.length
// if(i==arr.length){return true}
// else{return false}

/*
Maintain a variable maxReach that tracks the farthest index you can reach at any
point. Start from index 0 and iterate through the array. If at any index i, you
can reach that index (i.e., i <= maxReach), update maxReach to be the maximum of
its current value and i + nums[i]. If maxReach reaches or exceeds the last index
during the iteration, return true. If you finish the loop and haven't reached
the last index, return false.
*/

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int maxReach = 0;
    int n = nums.size();

    for (int i = 0; i <= n; i++) {
      if (i > maxReach) {
        return false;
      }
      maxReach = max(maxReach, i + nums[i]);
      if (maxReach >= n - 1) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  cout << "TestCase 1:" << endl;
  nums1[] = {2, 3, 1, 1, 4};
  cout << nums1 << endl;
  cout << Solution.canJump(nums1);

  cout << endl;
  cout << endl;

  cout << "TestCase 2:" << endl;
  nums2[] = {3, 2, 1, 0, 4};
  cout << nums2 << endl;
  cout << Solution.canJump(nums2);

  cout << endl;
  return 0;
}
