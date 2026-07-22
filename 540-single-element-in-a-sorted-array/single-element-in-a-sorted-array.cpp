// Map wala tarika (Sahi Syntax ke saath)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        // 1. Sabhi numbers ki frequency count karo
        for (int num : nums) {
            mp[num]++;
        }
        
        // 2. Wo number dhundho jiski frequency 1 hai
        for (int num : nums) {
            if (mp[num] == 1) {
                return num;
            }
        }
        
        return -1;
    }
};