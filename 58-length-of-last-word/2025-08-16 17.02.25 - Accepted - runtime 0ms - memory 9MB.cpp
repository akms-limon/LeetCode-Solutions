class Solution {
public:
    int lengthOfLastWord(string s) {
      int mx = INT_MIN;
      for (int i = 0; i < s.size(); i++) {
        int cnt = 0;
        while (i < s.size() && s[i] != ' ') {
          cnt++;
          i++;
        }
        if (cnt != 0)
        mx = cnt;
      }
      return mx;
    }
};