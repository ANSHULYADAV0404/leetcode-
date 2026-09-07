#include <algorithm>
#include <vector>

class Solution {
public:
    void getallcomb(int start, vector<int>& candidates, int target,
                    vector<int>& combination, vector<vector<int>>& ans) {
        // Base case: Valid combination found
        if (target == 0) {
            ans.push_back(combination);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // Skip duplicates at the current recursion level
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // Prune remaining branches if candidate exceeds remaining target
            if (candidates[i] > target)
                break;

            // Choose candidate
            combination.push_back(candidates[i]);

            // Recurse to next index (i + 1)
            getallcomb(i + 1, candidates, target - candidates[i], combination,
                       ans);

            // Backtrack
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combination;

        // 1. Sort once before starting recursion
        sort(candidates.begin(), candidates.end());

        // 2. Start recursion
        getallcomb(0, candidates, target, combination, ans);

        return ans;
    }
};