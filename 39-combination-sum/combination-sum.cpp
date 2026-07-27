class Solution {
public:
    set<vector<int>> st;
    void getallcomb(int i,vector<int>& arr, int target,vector<int> combination,vector<vector<int>>& ans){
        if(i==arr.size()||target<0){
            return;
        }
        if(target==0){
            if(st.find(combination)==st.end()){
                ans.push_back(combination);
                 st.insert(combination);
            }
            return;
        }
        combination.push_back(arr[i]);
        getallcomb(i+1,arr,target-arr[i],combination,ans);
        getallcomb(i,arr,target-arr[i],combination,ans);
        combination.pop_back();
        getallcomb(i+1,arr,target,combination,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int> combination;
        vector<vector<int>> ans;
        getallcomb(0,arr,target,combination,ans);
        return ans;
    }
};