class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size() , n=matrix[0].size();
        int s=0 , e=n-1;
        while(e>=0 && s<m){
            if(target == matrix[s][e]){
                return true;
            } else if(target < matrix[s][e]){
                e--;
            } else{
                s++;
            }
        }
      return false;  
    }
};