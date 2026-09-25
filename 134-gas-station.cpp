class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      vector<int> v;
      long long sum = 0;
      for (int i = 0; i < gas.size(); i++) {
       v.push_back(gas[i] - cost[i]);
       sum += gas[i] - cost[i];
      }
      if (sum < 0) return -1;
      long long temp = 0, total = 0;
      for (int i = 0; i < gas.size(); i++) {
        total += v[i];
        if (total < 0) {
          total = 0;
          temp = i + 1;
        }
      }
      return temp;
    }
};