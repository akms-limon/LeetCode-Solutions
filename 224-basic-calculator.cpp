class Solution {
public:
    int calculate(string s) {
        long long res = 0, cur = 0, sign = 1;
        stack<long long> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') continue;
            if (isdigit(s[i])) {
                cur = cur * 10 + (s[i] - '0');
            }
            else if (s[i] == '+') {
                res += cur * sign;
                cur = 0, sign = 1;
            }
            else if (s[i] == '-') {
                res += cur * sign;
                cur = 0, sign = -1;
            }
            else if (s[i] == '(') {
                st.push(res);
                st.push(sign);
                res = 0, sign = 1;
            }
            else if (s[i] == ')') {
                res += sign * cur;
                cur = 0;
                res = res * st.top();
                st.pop();
                res += st.top();
                st.pop();
            }
        }
        res += sign * cur;
        return res;
    }
};