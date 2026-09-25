class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<int> v;
        for (int i = 1; i < nums.size(); i++) {
            int k = 1;
            while (i < nums.size() && nums[i] > nums[i - 1]) {
                k++;
                i++;
            }
            v.push_back(k);
        }
        int ans = max(v[0] / 2, 1);
        for (int i = 1; i < (int) v.size(); i++) {
            ans = max(ans, v[i] / 2);
            ans = max(ans, min(v[i], v[i - 1]));
        }
        return ans;
    }
};