class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n - 2; i++) {
          if (nums[i] + nums[i + 2] == 0) {
            if (nums[i + 1] == 0) {
              cnt++;
            }
          }
          else if(nums[i + 1] % 2 == 0 && nums[i] + nums[i + 2] == nums[i + 1] / 2 && nums[i + 1] % (nums[i] + nums[i + 2]) == 0) {
            cout << i << ' ';
            cnt++;
          }
        }
        return cnt;
    }
};