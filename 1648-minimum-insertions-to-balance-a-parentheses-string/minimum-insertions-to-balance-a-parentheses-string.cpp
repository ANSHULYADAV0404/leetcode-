class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int insertion=0, n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
               st.push('(');
            } else{
                if(i+1<n&&s[i+1]==')'){
                    i++;
                } else{
                insertion++;
                }
            
            if(!st.empty()){
                st.pop();
            }else{
                insertion++;
            }
        }
      }

return insertion+(st.size()*2);
        
    }
};