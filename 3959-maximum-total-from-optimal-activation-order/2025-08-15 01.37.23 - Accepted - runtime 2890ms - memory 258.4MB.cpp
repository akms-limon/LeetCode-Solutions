class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
      vector<pair<int, int>> v;
      for (int i = 0; i < value.size(); i++) {
        v.push_back({limit[i], value[i]});
      }
      sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
      });
      long long active = 0, total = 0;
      for (int i = 0, j = 0; i < v.size(); i++) {
        cout << v[i].first << ' ' << active << '\n';
        if (v[i].first > active) {
          total += v[i].second;
          active++;
        }
        int cnt = 0;
        for (j; j < v.size();) {
          if (v[j].first <= active) {
            j++;
            cnt++;
          }
          else {
            break;
          }
        }
        i = max(i, j - 1);
        active = max(0LL, active - cnt);
      }
      return total;
    }
};