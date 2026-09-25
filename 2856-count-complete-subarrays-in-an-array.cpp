class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
      set<int> s;
      for (int i = 0; i < nums.size(); i++) {
        s.insert(nums[i]);
      }
      long long ans = 0;
      for (int i = 0; i < nums.size(); i++) {
        set<int> temp;
        for (int j = i; j < nums.size(); j++) {
          temp.insert(nums[j]);
          if (temp.size() == s.size()) {
            ans += nums.size() - j;
            break;
          }
        }
      }
      return ans;
    }
};