class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int n = numbers.size();
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      mp[numbers[i]]++;
    }
    vector<int> v;
    int temp;
    for (int i = 0; i < n; i++) {
      if (mp[target - numbers[i]]) {
        temp = target - numbers[i];
        v.push_back(i + 1);
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      if (numbers[i] == temp && v[0] != i + 1) {
        v.push_back(i + 1);
        break;
      }
    }
    return v;
  }
};