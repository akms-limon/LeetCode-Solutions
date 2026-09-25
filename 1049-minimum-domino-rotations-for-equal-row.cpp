class Solution {

public:
  int calc(const vector<int>& arr, const vector<int>& brr, int x) {
    bool bl = true;
    int cnt = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
      if (arr[i] != x) {
        if (brr[i] == x) {
          cnt++;
        }
        else {
          bl = false;
        }
      }
    }
    if (bl) {
      return min(cnt, n - cnt);
    }
    else {
      return INT_MAX;
    }
  }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
      int ans = INT_MAX;
      int a = tops[0], b = bottoms[0];
      int n = tops.size();
      ans = min(ans, calc(tops, bottoms, a));
      ans = min(ans, calc(tops, bottoms, b));
      ans = min(ans, calc(bottoms, tops, a));
      ans = min(ans, calc(bottoms, tops, b));
      if (ans == INT_MAX) {
        return -1;
      }
      return ans;
    }
};