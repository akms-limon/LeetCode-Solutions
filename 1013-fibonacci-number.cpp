class Solution {

vector<int> dp;

int fibo(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  if (dp[n] != -1) return dp[n];
  return dp[n] = fibo(n - 1) + fibo(n - 2);
}

public:
    int fib(int n) {
      dp.assign(n + 1, -1);
      return fibo(n);
    }
};