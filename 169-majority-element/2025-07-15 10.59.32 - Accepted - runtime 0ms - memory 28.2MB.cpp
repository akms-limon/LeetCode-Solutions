class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            if ((int)mp[nums[i]] > ((int)nums.size() / 2)) {
                ans = nums[i];
            }
        }
        return ans;
    }
};