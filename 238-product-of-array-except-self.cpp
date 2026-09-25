class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int pre[n], post[n];
        pre[0] = nums[0], post[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] * nums[i];
        }
        

        for (int j = n - 2; j >= 0; j--) {
            post[j] = post[j + 1] * nums[j];
        }
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                ans.push_back(post[i + 1]);
            }
            else if (i == n - 1) {
                ans.push_back(pre[i - 1]);
            }
            else
            ans.push_back(pre[i - 1] * post[i + 1]);
        }
        return ans;
    }
};