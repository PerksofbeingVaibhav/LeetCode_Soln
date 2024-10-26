/*91. Decode Ways
You have intercepted a secret message encoded as a string of numbers. The
message is decoded via the following mapping:

"1" -> 'A'

"2" -> 'B'

...

"25" -> 'Y'

"26" -> 'Z'

However, while decoding the message, you realize that there are many different
ways you can decode the message because some codes are contained in other codes
("2" and "5" vs "25").

For example, "11106" can be decoded into:

"AAJF" with the grouping (1, 1, 10, 6)
"KJF" with the grouping (11, 10, 6)
The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6"
is valid). Note: there may be strings that are impossible to decode.

Given a string s containing only digits, return the number of ways to decode it.
If the entire string cannot be decoded in any valid way, return 0. The test
cases are generated so that the answer fits in a 32-bit integer.


Example 1:
Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).

Example 2:
Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
6).

Example 3:
Input: s = "06"
Output: 0
Explanation:"06" cannot be mapped to "F" because of the leading zero ("6" is
different from "06"). In this case, the string is not a valid encoding, so
return 0.


Constraints:
1 <= s.length <= 100
s contains only digits and may contain leading zero(s).
*/

// Logic:
/*
dp[i]=dp[i+1]+dp[i+2]
make a tree like

121->
    121
    / \
   1   12
  / \    \
 2  21    1
/
1

for double digit start with 1, any no can be taken
but if start with 2 then 2nd digit b/w 0-6

else nothing will work with anyother starting

2 decision at every step -> 2^n complexity

how many diff ways can we decode subproblem

Iterative way:
use an array 'dp' to store number of ways to decode the string up to index i
checks if a substring of 2 characters forms a valid decoding (between 1 and 26),
and if so, it adds the number of ways to decode the rest of the string. dp[0]
holds the total number of ways to decode the entire string


Recursive way:
dfs function uses recursion with memoization to compute the number of ways to
decode the string starting from index i. If a solution for i has already been
computed, it returns the cached value. Similar logic is applied as in the
iterative approach: handle '0', check if two characters can form a valid
encoding, and recurse on the rest of the string. The base case is that if you
reach the end of the string, there is one way to decode it (doing nothing).

*/

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// Iterative - uses a vector dp where dp[i] holds the number of ways to decode
// the string from index i to the end.
/*
use an array 'dp' to store number of ways to decode the string up to index i
checks if a substring of 2 characters forms a valid decoding (between 1 and 26),
and if so, it adds the number of ways to decode the rest of the string. dp[0]
holds the total number of ways to decode the entire string
    */
class Solution {
public:
  // Iterative Bottom-Up DP approach
  int numDecodings(string s) {
    int n = s.length();
    vector<int> dp(n + 1, 0);
    dp[n] = 1; // Base case: one way to decode an empty string

    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '0') {
        dp[i] = 0; // No way to decode a string starting with '0'
      } else {
        dp[i] = dp[i + 1]; // One character decoding

        // Check if the two-character substring is valid (between "10" and "26")
        if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
          dp[i] += dp[i + 2];
        }
      }
    }
    return dp[0];
  }
};

// Recursive - leverages an unordered map memo to store previously computed
// results and avoid redundant calculations.
//  Recursive Top-Down approach with memoization
/*dfs function uses recursion with memoization to compute the number of ways to
 * decode the string starting from index i. If a solution for i has already been
 * computed, it returns the cached value. Similar logic is applied as in the
 * iterative approach: handle 'O', check if two characters can form a valid
 * encoding, and recurse on the rest of the string. The base case is that if you
 * reach the end of the string, there is one way to decode it (doing nothing).
 */
class Solution2 {
public:
  unordered_map<int, int> memo;

  int dfs(const string &s, int i) {
    if (memo.find(i) != memo.end())
      return memo[i];
    if (i == s.length())
      return 1; // Base case: end of the string
    if (s[i] == '0')
      return 0; // No way to decode a string starting with '0'

    int res = dfs(s, i + 1); // One character decoding

    // Check if two-character decoding is valid
    if (i + 1 < s.length() &&
        (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
      res += dfs(s, i + 2);
    }

    memo[i] = res;
    return res;
  }

  int numDecodings(string s) {
    memo.clear();
    return dfs(s, 0);
  }
};

int main() {
  Solution sol1;  // Iterative approach
  Solution2 sol2; // Recursive approach

  // Test cases
  string testCases[] = {"12", "226", "06"};
  int expectedResults[] = {2, 3, 0};

  for (int i = 0; i < 3; i++) {
    string s = testCases[i];
    int expected = expectedResults[i];

    // Call both solutions on the test case
    int result1 = sol1.numDecodings(s);
    int result2 = sol2.numDecodings(s);

    // Output the results
    cout << "Test case: " << s << endl;
    cout << "Expected: " << expected << endl;
    cout << "Iterative Result: " << result1 << endl;
    cout << "Recursive Result: " << result2 << endl;
    cout << "-----------------------------------" << endl;
  }

  return 0;
}
