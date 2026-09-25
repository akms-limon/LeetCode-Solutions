class Solution {
public:
    int dp[100000], inf = 1e9 + 7;
    int coin(int amount, vector<int> &coins) {
        if (dp[amount] != -1) return dp[amount];
        if (amount == 0) return 0;
        int ans = inf;
        for (int i = 0; i < coins.size(); i++) {
            if (amount - coins[i] >= 0) 
            ans = min(ans, coin(amount - coins[i], coins) + 1);
        }
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof dp);
        int ans = coin(amount, coins);
        return ans == inf ? -1 : ans;
    }
};