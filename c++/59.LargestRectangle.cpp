/*
84. Largest Rectangle in Histogram
Given an array of integers heights representing the histogram's bar height where
the width of each bar is 1, return the area of the largest rectangle in the
histogram.

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:
Input: heights = [2,4]
Output: 4

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104
*/

// Approach:Well what can we do
/*
get max term in array
then check it's either term
which is greater

for loop->
increase width for each increase in counter

decrease the height for each increase in counter

log them in an array

return max of that array
*/

// problem -> o(n^2)
// alter approach ->O(n)
/* Alter/Solution Approach:
* We will use a monotonic stack to keep track of the indices of the histogram's
bars in increasing order of heights. For each bar, we keep adding its index to
the stack if the current bar is taller than the bar at the index on top of the
stack. When a bar is encountered that is shorter than the bar at the top of the
stack, we calculate the area of the rectangle that can be formed using the bar
at the top of the stack as the shortest bar.*/

// Algorithm:
/*
 * 1. Initialize an empty stack to store indices.
2. Iterate through the array of heights:
 - While the current bar is shorter than the bar at the index at the top of the
stack, calculate the area for the height of the bar at the top of the stack.
 - Pop the stack and compute the width using the difference between the current
index and the index after popping from the stack.

3. After processing all bars, pop the remaining indices in the stack and compute
the areas.
*/

// Code:
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  int largestRectangleArea(std::vector<int> &heights) {
    std::stack<int> stack; // To store indices of heights
    int max_area = 0;
    int n = heights.size();

    for (int i = 0; i < n; ++i) {
      // Maintain an increasing stack, calculate area when height[i] <
      // height[stack.top()]
      while (!stack.empty() && heights[i] < heights[stack.top()]) {
        int h = heights[stack.top()]; // Get the height of the bar at the top of
                                      // the stack
        stack.pop();                  // Remove the top index

        int width;
        if (stack.empty()) {
          width = i; // If stack is empty, the width is the whole range from
                     // index 0 to i
        } else {
          width = i - stack.top() - 1; // Width is between the current index and
                                       // the one on top of the stack
        }

        max_area = std::max(max_area, h * width); // Update max area
      }
      stack.push(i); // Push the current index
    }

    // Process remaining bars in the stack
    while (!stack.empty()) {
      int h = heights[stack.top()];
      stack.pop();

      int width;
      if (stack.empty()) {
        width = n; // If stack is empty, width is the whole range
      } else {
        width = n - stack.top() - 1; // Calculate width for the remaining bars
      }

      max_area = std::max(max_area, h * width);
    }

    return max_area; // Return the maximum area
  }
};

int main() {
  Solution Solution;
  vector<int> heights1 = {2, 1, 5, 6, 2, 3};
  vector<int> heights2 = {2, 4};
  int output1 = 10;
  int output2 = 4;

  int testCase1 = Solution.largestRectangleArea(heights1);
  int testCase2 = Solution.largestRectangleArea(heights2);

  if (testCase1 == output1 && testCase2 == output2) {
    cout << "All test Case passed" << endl;
  } else {
    cout << "Error in Solution" << endl;
  }
  return 0;
}

//- Time complexity:O(n)
//- Space complexity:o(n)
