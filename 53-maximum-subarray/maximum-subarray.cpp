class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestval=nums[0];
        int ans= nums[0];
        for(int i=1;i<nums.size();i++){
            int a = nums[i]+bestval;
            int b = nums[i];
            bestval= max(a, b);
            ans=  max(bestval , ans);
        }
        return ans;
    }
};