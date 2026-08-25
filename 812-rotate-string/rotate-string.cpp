class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        string cant = s + s;

        if (cant.find(goal) != string::npos) {
            return true;
        } else {
            return false;
        }

        /// return true;
    }
};