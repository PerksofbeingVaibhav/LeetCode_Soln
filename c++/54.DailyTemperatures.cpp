/*
739. Daily Temperatures

Given an array of integers temperatures represents the daily temperatures,
return an array answer such that answer[i] is the number of days you have to
wait after the ith day to get a warmer temperature. If there is no future day
for which this is possible, keep answer[i] == 0 instead.

Example 1:
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Example 2:
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

Example 3:
Input: temperatures = [30,60,90]
Output: [1,1,0]


Constraints:
1 <= temperatures.length <= 10^5
30 <= temperatures[i] <= 100
*/

// Intuition
// It can be seen as Nearest Greater to Right. A standard Stack Problem but with
// index to maintain.

// Approach:
/*
Just store index along with element to keep count of index.

get the vector size, initialise a stack{st}
new vector initialise{ans size=n}

for loop on stack{
    stack must not be empty, stack.top().first<=ith elem of temp arra{
        pop the elements
    }
if(stack.empty()) ans[i]=0; //if stack is empty just set the corresponding array
elem to 0 else ans[i]=stack.top().second-i; push the temperatures
}

return vector
*/
// Time complexity:O(n^2)

// Space complexity:O(n)
class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    int n = temperatures.size();
    stack<pair<int, int>> st;

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && st.top().first <= temperatures[i]) {
        st.pop();
      }

      if (st.empty())
        ans[i] = 0;
      else
        ans[i] = st.top().second - i;
      st.push({temperatures[i], i});
    }
    return ans;
  }
};
