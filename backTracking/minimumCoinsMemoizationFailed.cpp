#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &v1, int x) {
  if (x < 0)
    return INT_MAX;
  if (x == 0)
    return 0;
  int minAns = INT_MAX;
  for (int i : v1) {
    int ans = solve(v1, x - i);
    if (ans != INT_MAX)
      minAns = min(minAns, ans + 1);
  }
  return minAns;
}
int solveMemo(vector<int> &v1, int x, vector<int> &memo) {
  if (x < 0)
    return INT_MAX;
  if (x == 0)
    return 0;
  if (memo[x] != -1)
    return memo[x];
  int minAns = INT_MAX;
  for (int i : v1) {
    int ans = solve(v1, x - i);
    if (ans != INT_MAX)
      minAns = min(minAns, ans + 1);
  }

  return memo[x] = minAns;
}
int solveTabu(vector<int> &v1, int x) {
  vector<int> dp(x + 1, INT_MAX);
  dp[0]=0;
  for (int i = 1; i <= x; i++) {
    for (int j = 0; j < v1.size(); j++) {
      if (i - v1[j] >= 0 && dp[i - v1[j]] != INT_MAX) {
        dp[i] = min(dp[i], dp[i - v1[j]] + 1);
      }
    }
  }
 
  return dp[x];
}
int minimumElements(vector<int> &num, int x) {
  int ans = solveTabu(num, x);
  if (ans == INT_MAX)
    return -1;
  vector<int> memo(num.size() + 1, -1);
  return ans;
}