class Solution {

public:

    vector<int> dp;

    int tribo(int n) {
      if (n == 0) return 0;
      if (n <= 2) return 1;
      if (dp[n] != -1) return dp[n];
      return dp[n] = tribo(n - 1) + tribo(n - 2) + tribo(n - 3);
    }
    
    int tribonacci(int n) {
      dp.assign(n + 1, -1);
      return tribo(n);
    }
};