class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int widsize=0;
        int ans=0;
        for(int h=0;h<nums.size();h++){
            widsize+=nums[h];
            while(widsize+k < h-l+1){
                widsize= widsize-nums[l];
                l++;
            }
            ans= max(ans,h-l+1);
        }
       return ans; 
    }
};