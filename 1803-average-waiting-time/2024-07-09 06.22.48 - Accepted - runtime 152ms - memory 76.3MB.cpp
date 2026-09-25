class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0, total = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (customers[i][0] >= total) {
                total = customers[i][0] + customers[i][1];
                ans += customers[i][1];
            }
            else {
                total += customers[i][1];
                ans += (total - customers[i][0]);
            }
        }
        ans /= customers.size();
        return ans;
    }
};