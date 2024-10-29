/*
118. Pascal's Triangle

Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above
it as shown:

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]

Constraints:
1 <= numRows <= 30
*/

// Intuition:
// well tree like structure
// each ith iteration has what i elements
// always set 0th, ith elements as 1 for each i
// also one observation, ith row has sort of i size array
// ith row has i-2 middle terms

/*Types of question:
 * Give R & C , find element at that place
 * Print nth row of pascal's triangle
 * Print entire Pascal's Triangle
 * {R-1} C {C-1} or (R-1,C-1)
 * find n!, r!, (n-r)!
 */

/*to find nCr->
int nCr(int n, int r) {
long long res = 1;
for(int i = 0;i<r;i++) {
res = res * (n - i);
res = res / (i + 1);
}
return res:}*/

// use long long to avoid overflow condition
/*
    for (c = 1; c <= n; c++) {
  print(fun nCr(n - 1, c - 1))
} // T.C.-> O(Nxr)
*/

// Optimisation:
// at column 0: ans=1
// column 1: ans=5
// column i: ans= ans*(row-col)/col
/*ans=1
 print(ans)
 for(int i=0;i<n;i++){
 ans=ans*(n-i);
 ans=ans/i;
 print {ans};
 }
    */
// TC:O(n), SC:O(1)

// New alter:
/*function(){
ans=[];
for(row=1 to n){
temp_list=[];
for(col=1 to row){
temp_list.add(nCr(row-1,col-1));
}
ans.add(temp_list);
}
return ans;}
*/

// Problem: O(n^3)

// optimised:
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> pascalTriangle(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); // First element is always 1
    for (int col = 1; col < row; col++) {
      ans = ans * (row - col); // Compute value using the binomial coefficient
      ans = ans / col;
      ansRow.push_back(ans); // Add the next element to the row
    }
    return ansRow;
  }

  vector<vector<int>> generate(int N) { // Corrected function name
    vector<vector<int>> ans;
    for (int i = 1; i <= N; i++) { // Generate rows from 1 to N
      ans.push_back(
          pascalTriangle(i)); // Generate each row and add it to the result
    }
    return ans;
  }
};

// Input : numRows = 1
// Output : [[1]]

// Input : numRows = 5
// Output : [ [1], [ 1, 1 ], [ 1, 2, 1 ], [ 1, 3, 3, 1 ], [ 1, 4, 6, 4, 1 ] ]

int main() {
  Solution solution;

  // Test Case 1: numRows = 1
  int numRows = 1;
  vector<vector<int>> result1 = solution.pascalTriangle(numRows);
  cout << "Pascal's Triangle for numRows = " << numRows << ":\n";
  for (const auto &row : result1) {
    for (int num : row) {
      cout << num << " ";
    }
    cout << endl;
  }

  // Test Case 2: numRows = 5
  numRows = 5;
  vector<vector<int>> result2 = solution.pascalTriangle(numRows);
  cout << "\nPascal's Triangle for numRows = " << numRows << ":\n";
  for (const auto &row : result2) {
    for (int num : row) {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}
