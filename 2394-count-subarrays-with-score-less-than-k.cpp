#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
      ll n = nums.size();
      vector<ll> pre(n);
      pre[0] = nums[0];
      for (ll i = 1; i < n; i++) {
        pre[i] = (pre[i - 1] + nums[i]);
      }
      ll ans = 0;
      for (ll i = 0; i < n; i++) {
        ll lo = i, mid, hi = n - 1;
        while (lo < hi) {
          mid = (lo + hi + 1) / 2;
          ll x = (pre[mid] - pre[i] + nums[i]);
          if (x * (mid - i + 1) < k) {
            lo = mid;
          }
          else {
            hi = mid - 1;
          }
        }
        if (lo == i && nums[i] < k) {
          ans++;
        }
        else if (lo != i) {
          ans += (lo - i + 1);
        }
      }
      return ans;
    }
};