class Solution {
public:
    long long coloredCells(int n) {
        long long ans=1;
        long long j = 4;
        for(int i = 1; i<n; i++){
            ans+=j;
            j+=4;
        }
        return ans;
    }
};