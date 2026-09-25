class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int cnt = 0;
        for (int i = 0; i < points.size(); i++) {
            int mn = points[i][0], mx = points[i][1];
            while (i < points.size() - 1 && points[i + 1][0] <= mx) {
                mn = points[i + 1][0];
                mx = min(points[i + 1][1], mx);
                i++;
            }
            cnt++;
        }
        return cnt;
    }
};