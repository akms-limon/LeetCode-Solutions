class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        long long mod = 1e9 + 7;
        map<int, int> cnt, sum;
        for (auto i : nums) {
            cnt[i] += (cnt[i + 1] + cnt[i - 1] + 1) % mod;
            cnt[i] %= mod;
            sum[i] += (sum[i + 1] + sum[i - 1]) % mod;
            sum[i] %= mod;
            sum[i] += (long long)(cnt[i + 1] + cnt[i - 1] + 1) % mod * i % mod;
            sum[i] %= mod;
        }
        int ans = 0;
        for (auto &it : sum) {
            ans = (ans % mod + it.second % mod) % mod;
        }
        return ans;
    }
};