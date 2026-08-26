class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        string cant = s + s;

        if (cant.contains(goal)) {
            return true;
        } else {
            return false;
        }

        /// return true;
    }
};