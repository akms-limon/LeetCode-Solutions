class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int j = 0, cnt = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != 0) {
        nums[j] = nums[i];
        j++;
      }
      else {
        cnt++;
      }
    }
    for (int i = nums.size() - 1; i > nums.size() - cnt - 1; i--) {
      nums[i] = 0;
    }
  }
};