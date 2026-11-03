class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int maxv=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxv=max(maxv,nums[i]);

        }
       return abs(sum-(maxv*n)); 
    }
};