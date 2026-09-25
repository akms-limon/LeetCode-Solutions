class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
      map<pair<int, int>, int> mp;
      int n = dominoes.size();
      for (int i = 0; i < n; i++) {
        if (dominoes[i][0] > dominoes[i][1]) {
          swap(dominoes[i][0], dominoes[i][1]);
        }
        mp[{dominoes[i][0], dominoes[i][1]}]++;
      }
      long long ans = 0;
      for (auto it : mp) {
        ans += (it.second * (it.second - 1)) / 2;
      }
      cout << '\n';
      return ans;
    }
};