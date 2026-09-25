class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(nums[i]);
        }
        int mx = 0;
        for (auto i : s) {
            if (s.find(i - 1) == s.end()) {
                int temp = i, cnt = 0;
                while (s.find(temp) != s.end()) {
                    temp++;
                    cnt++;
                }
                mx = max(mx, cnt);
            }
        }
        return mx;
    }
};