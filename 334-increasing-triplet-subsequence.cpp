class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
      set<int> s;
      vector<bool> check(nums.size());
      for (int i = 0; i < nums.size(); i++) {
        if (!s.empty() && *s.begin() < nums[i]) {
          check[i] = true;
        }
        s.insert(nums[i]);
      }
      s.clear();
      bool bl = false;
      for (int i = nums.size() - 1; i >= 0; i--) {
        if (!s.empty() && *(--s.end()) > nums[i] && check[i]) {
          bl = true;
          break;
        }
        s.insert(nums[i]);
      }
      return bl;
    }
};