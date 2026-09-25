class Solution {
public:
    int hIndex(vector<int>& citations) {
      int n = citations.size();
      int lo = 0, hi = n;
      while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
          if (citations[i] >= mid) {
            cnt++;
          }
        }
        cout << mid << ' ' << cnt << '\n';
        if (cnt >= mid) {
          lo = mid;
        }
        else {
          hi = mid - 1;
        }
      }
      return lo;
    }
};