class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int val : nums) {
            mp[val]++;
        }
        for (int val : nums) {
            if (mp[val] == 1) {
                return val;
            }
        }
        return -1;
    }
};