class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            int l = i, r = intervals[i][1];
            while (i < n - 1 && r >= intervals[i + 1][0]) {
                i++;
                r = max(r, intervals[i][1]);
            }
            r = max(intervals[i][1], r);
            ans.push_back({intervals[l][0], r});
        }
        return ans;
    }
};