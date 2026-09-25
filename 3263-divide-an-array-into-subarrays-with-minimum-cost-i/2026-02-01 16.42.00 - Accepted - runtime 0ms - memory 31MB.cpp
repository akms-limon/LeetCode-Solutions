class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int sum = nums[0];
        vector<int> a;
        for (int i = 1; i < nums.size(); i++) {
            a.push_back(nums[i]);
        }
        sort(a.begin(), a.end());
        return sum + a[0] + a[1];
    }
};