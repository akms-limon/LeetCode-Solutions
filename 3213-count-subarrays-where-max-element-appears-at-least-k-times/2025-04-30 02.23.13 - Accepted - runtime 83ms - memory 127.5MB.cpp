class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = INT_MIN;
        for (int i = 0; i < n; i++) {
          mx = max(mx, nums[i]);
        }
        cout << n << '\n';
        vector<int> pre(n);
        if (nums[0] == mx) pre[0] = 1;
        for (int i = 1; i < n; i++) {
          pre[i] = pre[i - 1];
          if (nums[i] == mx) {
            pre[i]++;
          }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
          int lo = i, hi = n - 1, mid;
          bool bl = false;
          int x;
          while (lo < hi) {
            mid = (lo + hi) / 2;
            x = pre[mid] - pre[i];
            if (nums[i] == mx && i != mid) {
              x++;
            }
            if (k == 1 && nums[mid] == mx) {
              x = 1;
            }
            if (x >= k) {
              bl = true;
              hi = mid;
            }
            else {
              lo = mid + 1;
            }
          }
          if (!bl) {
            x = pre[lo] - pre[i];
            if (nums[i] == mx && i != lo) {
              x++;
            }
            if (x >= k) {
              bl = true;
            }
            if (k == 1 && nums[lo] == mx) {
              x = 1;
              bl = true;
            }
          }
          if (bl) {
            ans += (n - lo);
          }
        }
        return ans;
    }
};