class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currcount=0, maxcount=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                currcount++;
                maxcount= max(currcount, maxcount);
            }else{
                currcount=0;
            }
        }
        return maxcount;
    }
};