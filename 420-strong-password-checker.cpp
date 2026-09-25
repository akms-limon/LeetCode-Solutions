class Solution {
public:
    int strongPasswordChecker(string password) {
      int n = password.size();
      string s = password;
      cout << n << '\n';
      bool digit = false, small = false, capital = false;
      for (int i = 0; i < n; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
          digit = 1;
        }
        else if (s[i] >= 'a' && s[i] <= 'z') {
          small = 1;
        }
        else {
          capital = 1;
        }
      }
      int ans = 0;
      if (n > 20) {
        ans += n - 20;
      }
      int insert = max(0, 6 - n), rep = 0, del = 0, two = 0, three = 0;
      for (int i = 0; i < n; i++) {
        char temp = s[i];
        int cnt = 0;
        while (i < n && s[i] == temp) {
          cnt++;
          i++;
        }
        i--;
        rep += (cnt / 3);
        if (ans > del && cnt % 3 == 0 && cnt >= 3) {
          rep--;
          del++;
          if (cnt > 3) {
            three += (cnt- 1) / 3;
          }
        }
        else if (ans > del + 1 && cnt % 3 == 1 && cnt > 3) {
          two ++;
          three += (cnt - 2) / 3;
        }
        else {
          three += (cnt / 3);
        }
      }
      int q = (ans - del) / 2;
      rep -= min(two, q);
      del += min(two, q) * 2;
      int p = (ans - del) / 3;
      rep -= min(three, p);
      rep = max(0, rep - insert);
      int total = insert + rep;
      if (total && !digit) total--;
      if (total && !small) total--;
      if (total && !capital) total--;
      ans += total;
      if (!digit) ans++;
      if (!small) ans++;
      if (!capital) ans++;
      return ans;
    }
};