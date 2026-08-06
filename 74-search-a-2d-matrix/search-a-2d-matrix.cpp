class Solution {
public:
    bool searchInrow(vector<vector<int>>& matrix, int target, int row){
        int n=matrix[0].size();
        int scol =0 , ecol =n-1;
        while(scol<=ecol){
          int  mid = scol+(ecol-scol)/2;
            if(target == matrix[row][mid]){
                return true;
            } else if(target >matrix[row][mid]){
                scol =mid+1;
            } else{
                ecol = mid-1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        int srow=0, erow=m-1;
        while(srow<=erow){
         int   midrow=srow+(erow-srow)/2;
            if(target>=matrix[midrow][0]&& target<=matrix[midrow][n-1]){
                return searchInrow(matrix, target, midrow);
            } else if(target>matrix[midrow][n-1]){
                srow = midrow+1;
            } else{
                erow = midrow-1;
            }
        }
       return false; 
    }
};