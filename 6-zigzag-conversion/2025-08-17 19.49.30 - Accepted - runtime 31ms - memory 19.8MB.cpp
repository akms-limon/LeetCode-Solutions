class Solution {
public:
  string convert(string s, int numRows) {
    vector<vector<char>> v(numRows);
    int i = 0, row = 0, flag = 0;
    while (i < s.size()) {
      if (flag == 0) {
        for (int j = 0; j < numRows; j++) {
          v[j].push_back(s[i]);
          i++;
          if (i >= s.size()) break;
        }
      }
      else {
        for (int j = numRows - 2; j > 0; j--) {
          v[j].push_back(s[i]);
          i++;
          if (i >= s.size()) break;
        }
      }
      flag ^= 1;
    }
    string ans;
    for (auto it : v) {
      for (auto x : it) {
        ans.push_back(x);
      }
    }
    return ans;
  }
};