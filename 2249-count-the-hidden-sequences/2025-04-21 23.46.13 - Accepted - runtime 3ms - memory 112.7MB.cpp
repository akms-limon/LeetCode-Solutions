class Solution {
public:
  int numberOfArrays(vector<int>& differences, int lower, int upper) {
    long long n = differences.size();
    long long cur = lower, mn = cur, mx = cur;
    for (long long i = 0; i < n; i++) {
      cur = differences[i] + cur;
      mn = min(mn, cur);
      mx = max(mx, cur);
    }
    if (mn < lower) {
      long long x = lower - mn;
      mn = lower;
      mx += x;
    }
    if (mx > upper) return 0;
    return upper - mx + 1;
  }
};