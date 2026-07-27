class Solution {
public:
 void allss (int i,vector<int>&subset, vector<int>& nums, vector<vector<int>>& ans){
    if(i==nums.size()){
        ans.push_back(subset);
        return;
    }
    subset.push_back(nums[i]);
    allss(i+1,subset,nums,ans);
    subset.pop_back();
     allss(i+1,subset,nums,ans);

 }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans;
       vector<int> subset;
       allss(0, subset, nums, ans);
       return ans; 
        
    }
};