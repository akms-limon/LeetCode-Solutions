class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;
    map<tuple<int, int, int>, bool> mp;
    for (int i = 0; i < n; i++) {
      if (i && nums[i] == nums[i - 1]) continue;
      int j = i + 1, k = n - 1;
      while (j < k) {
        int total = nums[i] + nums[j] + nums[k];
        if (total > 0) k--;
        else if (total < 0) j++;
        else {
          if (!mp[{nums[i], nums[j], nums[k]}]) {
            ans.push_back({nums[i], nums[j], nums[k]});
            mp[{nums[i], nums[j], nums[k]}] = true;
          }
          k--;
        }
      }
    }
    return ans;
  }
};