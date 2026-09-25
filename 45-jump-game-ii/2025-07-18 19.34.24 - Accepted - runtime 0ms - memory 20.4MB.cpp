class Solution {
public:
    int jump(vector<int>& nums) {
      int n = nums.size();
      int cnt = 0;
      if (n == 1) return 0;
      for (int i = 0; i < n; i++) {
        cnt++;
        if (i + nums[i] >= n - 1) break;
        int mx = INT_MIN, ind = i + 1;
        for (int j = i + 1; j <= i + nums[i]; j++) {
          if (nums[j] + j > mx) {
            ind = j;
            mx = nums[j] + j;
          }
        }
        i = ind - 1;
      }
      return cnt;
    }
};