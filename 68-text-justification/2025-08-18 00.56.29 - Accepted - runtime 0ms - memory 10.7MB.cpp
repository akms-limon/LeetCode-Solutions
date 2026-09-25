class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
      int n = words.size();
      vector<string> ans;
      for (int i = 0; i < n; i++) {
        vector<string> temp;
        int space = 0, total = 0, bl = 0;
        while (i < n && total + bl + words[i].size() <= maxWidth) {
          temp.push_back(words[i]);
          total += words[i].size();
          if (bl) total++;
          bl = 1;
          space++;
          i++;
        }
        i--;
        space--;
        int total_space = maxWidth - total;
        total_space += space;
        int every = total_space, extra = total_space;
        if (space) {
          every = total_space / space;
          extra = total_space % space;
        }
        if (i == n - 1) {
          string s;
          for (int j = 0; j < temp.size(); j++) {
            s += temp[j];
            if (j != temp.size() - 1) {
              s += ' ';
            }
          }
          while (s.size() < maxWidth) {
            s += ' ';
          }
          ans.push_back(s);
          break;
        }
        if (temp.size() == 1) {
          string s;
          s = temp[0];
          while (s.size() < maxWidth) {
            s += ' ';
          }
          ans.push_back(s);
        }
        else {
          string s;
          for (int j = 0; j < temp.size(); j++) {
            s += temp[j];
            if (j != temp.size() - 1) {
              for (int k = 0; k < every; k++) {
                s += ' ';
              }
              if (extra) {
                s += ' ';
                extra--;
              }
            }
          }
          ans.push_back(s);
        }
      }
      return ans;
    }
};