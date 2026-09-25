class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
      int n = nums.size();
      sort(nums.begin(), nums.end());
      int ans = 0;
      for (int i = 0, j = n - 1; i < j; ) {
        if (nums[j] + nums[i] > k) {
          j--;
        }
        else if (nums[j] + nums[i] == k) {
          ans++;
          i++, j--;
        }
        else if (nums[i] + nums[j] < k) {
          i++;
        }
      }
      return ans;
    }
};