class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        string left = "([{";
        string right = ")]}";

        for (char c: s) {
            if (left.find(c) != string::npos) {
                // 왼쪽
                st.push(c);
            } else {
                int pos = right.find(c);
                if (!st.empty() && left.find(st.top()) == right.find(c)){
                    st.pop();
                } else {
                    st.push(c);
                }
            }
        }
        return st.empty();
    }
};