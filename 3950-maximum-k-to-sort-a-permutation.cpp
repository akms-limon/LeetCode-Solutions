class Solution {
public:
    int sortPermutation(vector<int>& nums) {
      int ans = 0;
      ans = ~(ans);
      bool bl = false;
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != i) {
          ans &= nums[i];
          bl = true;
        }
      }
      if (bl)
      return ans;
      else return 0;
    }
};