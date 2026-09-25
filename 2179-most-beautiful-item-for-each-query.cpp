class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int mx = INT_MIN;
        for (int i = 0; i < items.size(); i++) {
            mx = max(mx, items[i][1]);
            items[i][1] = mx;
        }
        vector<int> ans;
        for (int i = 0; i < (int)queries.size(); i++) {
            auto it = upper_bound(items.begin(), items.end(), vector<int>{queries[i], INT_MAX});
            if (it == items.begin()) {
                ans.push_back(0);  
            } else {
                --it;
                ans.push_back((*it)[1]); 
            }
        }
        return ans;
    }
};
