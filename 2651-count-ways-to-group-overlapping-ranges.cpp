class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        int n = ranges.size();
        sort(ranges.begin(), ranges.end());
        int lo = ranges[0][0], hi = ranges[0][1];
        int cnt = 1;
        for(int i = 1; i<n; i++){
            if(ranges[i][0]>hi){
                cnt++;
                hi = ranges[i][1];
            }
            else {
                hi = max(ranges[i][1], hi);
            }
        }
        int ans = 1;
        for(int i = 1; i<=cnt; i++){
            ans=(ans*2)% 1000000007;
        }
        
        return ans;
    }
};