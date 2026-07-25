class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        //int m=A.size(), int n=B.size();
        int last=m+n-1, i=m-1,j=n-1;
        while(i>=0&&j>=0){
            if(A[i]>B[j]){
                A[last]=A[i];
                last--;
                i--;
            } else{
                A[last]= B[j];
                last--;
                j--;

            }
        }
        while(j>=0){
            A[last]=B[j];
            last--;
            j--;
        }
    }
};