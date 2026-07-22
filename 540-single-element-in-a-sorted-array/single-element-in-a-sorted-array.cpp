class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int n = A.size();
        if (n == 1)
            return A[0];
        int lp = 0, rp = n - 1, mid;
        while (lp <= rp) {
            mid = lp + (rp - lp) / 2;
            if (mid == 0 && A[0] != A[1])
                return A[0];
            if (mid == n - 1 && A[n - 1] != A[n - 2])
                return A[n - 1];
            if (A[mid - 1] != A[mid] && A[mid + 1] != A[mid])
                return A[mid];
            if (mid % 2 == 0) {
                if (A[mid - 1] == A[mid]) {
                    rp = mid - 1;
                } else {
                    lp = mid + 1;
                }
            } else {
                if (A[mid - 1] == A[mid]) {
                    lp = mid + 1;
                } else {
                    rp = mid - 1;
                }
            }
        }
        return mid;
    }
};