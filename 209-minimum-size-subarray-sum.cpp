class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int sum = 0, ans = INT_MAX;
    int i = 0, j = 0;
    while (j < n) {
      bool bl = false;
      while (j < n && sum < target) {
        sum += nums[j];
        if (sum >= target) bl = true;
        j++;
      }
      while (i < j && sum >= target) {
        sum -= nums[i];
        i++;
      }
      if (bl)
      ans = min(ans, j - i + 1);
    }
    if (ans == INT_MAX) return 0;
    return ans;
  }
};