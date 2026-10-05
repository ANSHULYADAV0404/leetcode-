class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> vs(256,0);
        vector<int> vt(256,0);
        for(int i=0;i<s.size();i++){
            if(vs[s[i]]!=vt[t[i]]){
                return false;
            }
            vs[s[i]]=i+1;
            vt[t[i]]=i+1;
        }

      return true;
    }
};