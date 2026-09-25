class Solution {
public:
    string pushDominoes(string dominoes) {
      string s = dominoes;
      int n = s.size();
      int firstl = -1, lastl = -1, firstr = -1, lastr = -1;
      for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
          lastr = i;
        }
        if (s[i] == 'L') {
          lastl = i;
        }
        if (s[i] == 'R' && firstr == -1) {
          firstr = i;
        }
        if (s[i] == 'L' && firstl == -1) {
          firstl = i;
        }
      }
      if (lastr == -1) firstr = n;
      bool bl = false;
      for (int i = firstr - 1; i >= 0; i--) {
        if (s[i] == 'L') bl = true;
        if (bl) {
          s[i] = 'L';
        }
      }
      if (lastl == -1) lastl = 0;
      bl = false;
      for (int i = lastl; i < n; i++) {
        if (s[i] == 'R') bl = true;
        if (bl) {
          s[i] = 'R';
        }
      }
      if (firstr == -1) firstr = n;
      if (firstl == -1) firstl = n;
      for (int i = firstr; i < lastl; i++) {
        if (s[i] == 'R') {
          int temp = i;
          i++;
          int ind = i;
          while ((s[i] == '.') && i < lastl) {
            i++;
            ind = i;
          }
          cout << temp << ' ' << ind << '\n';
          if (s[ind] == 'R') {
            for (int j = temp; j <= ind; j++) {
              s[j] = 'R';
            }
            i--;
          }
          else if (s[ind] == 'L') {
            for (int j = temp; j <= (temp + ind) / 2; j++) {
              s[j] = 'R';
            }
            for (int j = ((temp + ind) / 2) + 1; j <= ind; j++) {
              s[j] = 'L';
            }
            if ((ind - temp) % 2 == 0) {
              s[((temp + ind) / 2)] = '.';
            }
          }
        }
      }
      for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
          i++;
          int temp = i;
          int ind = i;
          while (i < n && s[i] == '.') {
            i++;
            ind = i;
          }
          if (s[ind] == 'L') {
            for (int j = temp; j < ind; j++) {
              s[j] = 'L';
            }
          }
          i--;
        }
      }
    return s;
    }
};