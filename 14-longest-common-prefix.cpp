class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      string ans = strs[0];
     for (int i = 0; i < strs.size(); i++) {
      int j = 0;
      string temp;
      int mn = min(strs[j].size(), ans.size());
      while (j < mn && strs[i][j] == ans[j]) {
        temp.push_back(ans[j]);
        j++;
      }
      ans = temp;
     }
     return ans;
    }
};