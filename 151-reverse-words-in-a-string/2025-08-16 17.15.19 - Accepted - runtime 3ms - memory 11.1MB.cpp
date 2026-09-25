class Solution {
public:
    string reverseWords(string s) {
      vector<string> v;
      for (int i = 0; i < s.size(); i++) {
        string temp;
        while (i < s.size() && s[i] != ' ') {
          temp.push_back(s[i]);
          i++;
        }
        if (temp.size())
        v.push_back(temp);
      }
      reverse(v.begin(), v.end());
      string ans;
      for (int i = 0; i < v.size(); i++) {
        ans += v[i];
        if (i != v.size() - 1) {
          ans += " ";
        }
      }
      return ans;
    }
};