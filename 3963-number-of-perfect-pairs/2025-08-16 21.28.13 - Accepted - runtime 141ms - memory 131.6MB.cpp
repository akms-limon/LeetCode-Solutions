class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
      int n = nums.size();
      for (int i = 0; i < n; i++) {
        nums[i] = abs(nums[i]);
      }
      sort(nums.begin(), nums.end());
      long long ans = 0;
      for (int i = 0; i < n - 1; i++) {
        int lo = i, hi = n - 1;
        bool bl = false;
        while (lo < hi) {
          int mid = (lo + hi + 1) / 2;
          int a = nums[i], b = nums[mid];
          int x = abs(a - b);
          int y = abs(a + b);
          if (min(x, y) <= min(abs(a), abs(b)) && max(x, y) >= max(abs(a), abs(b))) {
            bl = true;
            lo = mid;
          }
          else {
            hi = mid - 1;
          }
        }
        if (bl)
        ans += lo - i;
      }
      return ans;
    }
};