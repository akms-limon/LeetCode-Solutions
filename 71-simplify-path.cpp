class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string s;
        while (getline(ss, s, '/')) {
            if (s == "" || s == ".") {
                continue;
            }
            if (s == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            }
            else {
                st.push(s);
            }
        }
        vector<string> v;
        while (!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(), v.end());
        string ans = "/";
        for (int i = 0; i < v.size(); i++) {
            ans += v[i] + "/";
        }
        if (ans[ans.size() - 1] == '/' && ans.size() > 1) ans.pop_back();
        return ans;
    }
};