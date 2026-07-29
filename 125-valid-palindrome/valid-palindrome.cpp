class Solution {
public:
    bool isalnum(char ch) {
        if ((ch >= '0' && ch <= '9') ||
            (tolower(ch) >= 'a' && tolower(ch) <= 'z')) {
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int start = 0, end = s.size() - 1;
        while (start < end) {
            if (!isalnum(s[start])) {
                start++;
                continue;
            }
            if (!isalnum(s[end])) {
                end--;
                continue;
            }

            if (tolower(s[start]) != tolower(s[end])) {
                // swap(s[start],s[end]);
                // start++;
                // end--;

                return false;
            }

            start++;
            end--;
        }
        return true;
    }
};