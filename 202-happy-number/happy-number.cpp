class Solution {
public:
    int squaresum(int n) {
        int sum = 0;
        while (n > 0) {
            int dig = n % 10;
            n = n / 10;
            sum += dig * dig;
        }
        return sum;
    };
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = squaresum(slow);
            fast = squaresum(squaresum(fast));
        } while (slow != fast);

        return slow == 1;
    }
};