class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int lo = 1, hi = 1e6;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int cnt = 0;
            for (int i = 0; i < quantities.size(); i++) {
                if (quantities[i] % mid) {
                    cnt++;
                }
                cnt += (quantities[i] / mid);
            }
            if (cnt <= n) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};