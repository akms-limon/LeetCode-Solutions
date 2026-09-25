class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0, l = newInterval[0], r = newInterval[1];
        while (i < intervals.size() && intervals[i][1] < l) {
            ans.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }
        vector<int> temp{l, r};
        while (i < intervals.size() && intervals[i][0] <= r) {
            temp.push_back(intervals[i][0]);
            temp.push_back(intervals[i][1]);
            i++;
        }
        sort(temp.begin(), temp.end());
        ans.push_back({temp[0], temp[temp.size() - 1]});
        while (i < intervals.size()) {
            ans.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }
        return ans;
    }
};