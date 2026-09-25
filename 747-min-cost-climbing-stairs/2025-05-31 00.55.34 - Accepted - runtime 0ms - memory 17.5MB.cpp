const int N = 1000 + 10;
int dp[N];

long long mincost(vector<int> &cost, int n) {
  if (n <= 1) return cost[n];
  if (dp[n] != -1) return dp[n];
  return dp[n] = min(mincost(cost, n - 1), mincost(cost, n - 2)) + cost[n];
}

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
      cost.push_back(0);
      int n = cost.size();
      for (int i = 0; i < n; i++) {
        dp[i] = -1;
      }
      return mincost(cost, n - 1);
    }
};