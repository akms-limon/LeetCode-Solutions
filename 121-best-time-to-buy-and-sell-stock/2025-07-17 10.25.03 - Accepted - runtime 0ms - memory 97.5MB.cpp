class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int ans = 0, mn = INT_MAX;
      for (auto p : prices) {
        mn = min(mn, p);
        ans = max(ans, p - mn);
      }
      return ans;
    }
};