class Solution {
public:
    int minSensors(int n, int m, int k) {
      int ans = (n + 2 * k) / (2 * k + 1);
      ans *= (m + 2 * k) / (2 * k + 1);
      return ans;
    }
};