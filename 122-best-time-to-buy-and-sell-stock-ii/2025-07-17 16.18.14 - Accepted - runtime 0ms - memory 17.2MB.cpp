class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int n = prices.size(), ans = 0;
      for (int i = 0; i < n; i++) {
        int mn = prices[i];
        while (i < n - 1 && prices[i] < prices[i + 1]) {
          i++;
        }
        ans += prices[i] - mn;
      }
      return ans;
    }
};