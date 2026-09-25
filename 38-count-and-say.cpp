class Solution {
public:
  string countAndSay(int n) {
    string s = "1";
    for (int j = 2; j <= n; j++) {
      string temp;
      for (int i = 0; i < s.size(); i++) {
        int cnt = 1;
        while (i < s.size() - 1 && s[i] == s[i + 1]) {
          cnt++;
          i++;
        }
        string p = to_string(cnt);
        temp += p + s[i];
        cout << s[i] << " : " << cnt << '\n';
      }
      s = temp;
    }
    return s;
  }
};