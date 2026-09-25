class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> ind;
        for (int i = 0; i < nums.size(); i++) {
            if (ind[nums[i]]) {
                if (i + 1 - ind[nums[i]] <= k) {
                    return true;
                }
            }
            ind[nums[i]] = i + 1;
        }
        return false;
    }
};