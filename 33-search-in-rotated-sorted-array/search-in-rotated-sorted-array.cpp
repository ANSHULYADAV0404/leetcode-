class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lb=0,ub=n-1,mid;
        while(lb<=ub){
            mid=lb+(ub-lb)/2;
            if (nums[mid] == target) {
                return mid;
            }
            if(nums[lb]<=nums[mid]){
                if(target>=nums[lb]&&target<nums[mid]){
                    ub = mid-1;
                 
                }else{
                    lb = mid+1;
                }
            }else{
               if(target>nums[mid]&&target<=nums[ub]){
                    lb = mid+1;
                 
                }else{
                    ub = mid-1;
                } 
            }
        }
        return -1;
    }
};