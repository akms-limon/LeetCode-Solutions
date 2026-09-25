const int N = 50;
int dp[N];

int total(int n) {
  if (n == 1) return 1;
  if (n == 2) return 2;
  if (dp[n]) return dp[n];
  return dp[n] = total(n - 1) + total(n - 2);
}

class Solution {
public:
    int climbStairs(int n) {
      return total(n);
    }
};