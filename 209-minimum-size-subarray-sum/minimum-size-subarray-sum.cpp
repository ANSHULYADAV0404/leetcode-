class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int widsize= INT_MAX;
        int currsum=0;
        for(int h=0;h<nums.size();h++){
            currsum+=nums[h];
          while(currsum>=target){
            //h++;
            widsize=min(h-l+1, widsize);
            currsum -= nums[l];
            l++;
          }
        }
       return (widsize == INT_MAX) ? 0 : widsize; //not valid h 
    }
};