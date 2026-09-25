class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool bl = true;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')') {
                if (st.empty()) {
                    bl = false;
                }
                else {
                    if (st.top() == '(') {
                        st.pop();
                    }
                    else bl = false;
                }
            }
            else if (s[i] == '}') {
                if (st.empty()) {
                    bl = false;
                }
                else {
                    if (st.top() == '{') {
                        st.pop();
                    }
                    else bl = false;
                }
            }
            else if (s[i] == ']') {
                if (st.empty()) {
                    bl = false;
                }
                else {
                    if (st.top() == '[') {
                        st.pop();
                    }
                    else bl = false;
                }
            }
            else st.push(s[i]);
        }
        if (!st.empty()) bl = false;
        return bl;
    }
};
