class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        
        while (columnNumber > 0) {
            columnNumber--; // 1-based ko 0-based mein shift karne ke liye
            int rem = columnNumber % 26;
            result.push_back('A' + rem);
            columnNumber /= 26;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};