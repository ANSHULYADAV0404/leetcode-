class Solution {
public:
    int addDigits(int num) {
      if (num == 0) return 0;
        if (num % 9 == 0) return 9; // 9, 18, 27, etc. ka sum hamesha 9 hoga, 0 nahi
        return num % 9;  
    }
};