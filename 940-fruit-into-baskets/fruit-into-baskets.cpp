class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0 , size=0;
       int maxlen =0;
        unordered_map<int, int> mp;
        for(int h=0;h<fruits.size();h++){
            mp[fruits[h]]++;
            while(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
               l++;
            }
            maxlen =max(h-l+1,maxlen);
        }

    return maxlen;
        
    }
};