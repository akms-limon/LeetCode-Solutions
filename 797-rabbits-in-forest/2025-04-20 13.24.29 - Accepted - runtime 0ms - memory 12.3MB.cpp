class Solution {
public:
  int numRabbits(vector<int>& answers) {
    map<int, int> mp;
    long long ans = 0;
    for (int i = 0; i < answers.size(); i++) {
      mp[answers[i]]++;
    }
    for (auto it : mp) {
      ans += ((it.second + it.first) / (it.first + 1)) * (it.first + 1);
    }
    return ans;
  }
};