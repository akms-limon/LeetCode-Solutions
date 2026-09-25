class Solution {
    static const int N = 2500;
    int dp[N];
    int n;
    vector<int> a;

public:
    int lis(int i) {
        if (dp[i] != -1) return dp[i];
        int ans = 1;
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                ans = max(ans, lis(j) + 1);
            }
        }
        return dp[i] = ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        a = nums;
        n = nums.size();
        int ans = 1;
        for (int i = 0; i < n; i++) {
            ans = max(ans, lis(i)); // ✅ Function call
        }
        return ans;
    }
};
