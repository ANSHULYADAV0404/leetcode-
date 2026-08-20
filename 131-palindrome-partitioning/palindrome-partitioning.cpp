class Solution {
public: 
    bool ispalindrome(string s){
        string s2=s;
        reverse(s2.begin(),s2.end());
        return s==s2;
    }
    void getalls(string s,vector<string> &partions, vector<vector<string>> &ans){
        if(s.size()==0){
            ans.push_back(partions);
            return;
        }
        for(int i=0;i<s.size();i++){
            string part= s.substr(0,i+1);
            if(ispalindrome(part)){
                partions.push_back(part);
                getalls(s.substr(i+1),partions, ans);
                partions.pop_back();
            }
        }
        //return
    }
    vector<vector<string>> partition(string s) {
        vector<string> partions;
        vector<vector<string>> ans;
        getalls(s,partions,ans);
        return ans;
        
    }
};