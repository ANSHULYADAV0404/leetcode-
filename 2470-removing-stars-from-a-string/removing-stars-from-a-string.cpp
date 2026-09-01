class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '*') {
                if (!st.empty())
                    st.pop(); // Remove previous character
            } else {
                st.push(ch); // Push normal characters
            }
        }
        string result = "";
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};