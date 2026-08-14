class Solution {
public:
     void getallss(vector<int>&nums, vector<vector<int>>&subsets, vector<int>& ans, int i){
        if(i==nums.size()){
            subsets.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        getallss(nums, subsets, ans,i+1);
        ans.pop_back();
        int idx=i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]) idx++;
        getallss(nums,subsets,ans,idx);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> ans;
        sort(nums.begin(),nums.end());
        getallss(nums,subsets,ans,0);
        return subsets;
    }
};