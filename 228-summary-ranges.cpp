class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        string temp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            while (i < n - 1 && nums[i + 1] == nums[i] + 1) {
                i++;
            }
            r = i;
            temp = to_string(nums[l]);
            if (l != r){
                temp += "->";
                temp += to_string(nums[r]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};