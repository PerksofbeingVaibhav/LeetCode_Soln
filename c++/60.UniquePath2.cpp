/* 63. Unique Paths II
You are given an m x n integer array grid. There is a robot initially located at
the top-left corner (i.e., grid[0][0]). The robot tries to move to the
bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either
down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the
robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the
bottom-right corner.

The testcases are generated so that the answer will be less than or equal to
2*10^9.

Example 1:
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2

Explanation: There is one obstacle in the middle of the 3x3 grid above. There
are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right


Example 2:
Input: obstacleGrid = [[0,1],[0,0]]
Output: 1

Constraints:
m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.
*/

// Anything:
/*
well see check where is obstacle like in right or down, if(obstacle) move down
or right else move right or down

check after each iteration
make a tree for each new iteration path taken
count no of leaf nodes at last

avoid any cells with obstacles (marked by 1)
*/

// Algo
/*
1. if starting grid itself is blocked that is {obstacleGrid[0][0] == 1} return 0
 * else dp[0][0]=1

2. if(obstacleGrid[i][j] == 1){dp[i][j] = 0}    //can't pass through it
    else{number of ways to reach a cell (i, j) is the sum of the ways to reach
the cell from the top (dp[i-1][j]) and the ways to reach the cell from the left
(dp[i][j-1]), provided those cells are within bounds}

3. After filling up the dp table, the value at dp[m-1][n-1] (bottom-right
corner) will be the number of unique paths to reach the destination.

*/
/*
#include <vector>
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    // if starting grid is blocked
    if (obstacleGrid[0][0] == 1) {
      return 0;
    }

    // initialise DP array
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // initialise a start point
    dp[0][0] = 1;

    // Fill first column
    for (int i = 0; i < m + 1; i++) {
      if (obstacleGrid[i][0] == 0) {
        dp[i][0] = dp[i - 1][0];
      } else {
        dp[i][0] = 0;
      }
    }

    // fill first row
    for (int j = 0; j < n; j++) {
      if (obstacleGrid[0][j] == 0) {
        dp[0][j] = dp[0][j - 1];
      } else {
        dp[0][j] = 0;
      }
    }
    // fill rest of dp array
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (obstacleGrid[i][j] == 0) {
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        } else {
          dp[i][j] = 0;
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};
*/
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)

// fucking run time error, reasons:
/*Indexing Errors: The loops accessing dp[i - 1] or dp[0][j - 1] for i == 0 or j
== 0 would cause out-of-bounds errors. These conditions need to be handled
separately for the first row and column.

Loop Ranges: The first column loop has a condition i < m + 1, which should be i
< m. Similarly, in the main loop, i and j should start from 1 instead of 0 after
initializing the first row and column separately.

Initializations: After initializing the DP array, filling the first row and
column should handle boundary cases when the starting or blocking point has
obstacles.*/

/* Key Fixes:
Boundary conditions in the first column and row are handled separately.
Loop ranges: Corrected the loop starting from 1 in the inner loops and fixed the
first row/column initialization. The result is the value stored in dp[m - 1][n -
1].*/

#include <vector>
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    // If the starting point has an obstacle, return 0.
    if (obstacleGrid[0][0] == 1) {
      return 0;
    }

    // Initialize DP array
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Start point initialization
    dp[0][0] = 1;

    // Fill the first column
    for (int i = 1; i < m; i++) {
      dp[i][0] = (obstacleGrid[i][0] == 0 && dp[i - 1][0] == 1) ? 1 : 0;
    }

    // Fill the first row
    for (int j = 1; j < n; j++) {
      dp[0][j] = (obstacleGrid[0][j] == 0 && dp[0][j - 1] == 1) ? 1 : 0;
    }

    // Fill the rest of the dp array
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (obstacleGrid[i][j] == 0) {
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        } else {
          dp[i][j] = 0;
        }
      }
    }

    return dp[m - 1][n - 1];
  }
};
