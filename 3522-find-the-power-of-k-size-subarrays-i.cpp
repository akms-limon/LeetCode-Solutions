class Solution {
public:
  vector<int> resultsArray(vector<int>& nums, int k) {
    vector<int> ans;
    queue<int> pq;
    for (int i = 0; i < nums.size(); i++) {
      if (pq.empty()) {
        pq.push(nums[i]);
        i++;
      }
      while (pq.size() < k && i < nums.size() && nums[i] == nums[i - 1] + 1) {
        pq.push(nums[i]);
        i++;
      }
      i--;
      if (pq.size() == k) {
        if (ans.size() <= nums.size() - k)
        ans.push_back(pq.back());
        pq.pop();
      }
      else {
        while (!pq.empty()) {
          if (ans.size() <= nums.size() - k)
          ans.push_back(-1);
          pq.pop();
        }
      }
    }
    return ans;
  }
};