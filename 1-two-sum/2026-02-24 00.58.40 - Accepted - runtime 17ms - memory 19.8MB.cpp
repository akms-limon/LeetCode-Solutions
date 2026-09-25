class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int x, y, n = nums.size();
        unordered_map<int, int> mp, ind;
        for (int i = 0; i < n; i++) {
            if (mp[target - nums[i]]) {
                x = ind[target - nums[i]];
                y = i;
            }
            else {
                mp[nums[i]]++;
                ind[nums[i]] = i;
            }
        }
        return {x, y};
    }
};