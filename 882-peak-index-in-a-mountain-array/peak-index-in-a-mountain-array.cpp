class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int lb = 1, ub = n - 2;
        int mid;
        while (lb <= ub) {
             mid = lb + (ub - lb) / 2;
            if (arr[mid - 1] < arr[mid] && arr[mid + 1] < arr[mid])
                return mid;
            else if (arr[mid - 1] < arr[mid]) {
                lb = mid + 1;
            } else {
                ub = mid - 1;
            }
        }
        return mid;
    }
};
