class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({score[i], i});
        }
        vector<string> ans(n);
        if (!pq.empty()) {
            ans[pq.top().second] = "Gold Medal";
            pq.pop();
        }
        if (!pq.empty()) {
            ans[pq.top().second] = "Silver Medal";
            pq.pop();
        }
        if (!pq.empty()) {
            ans[pq.top().second] = "Bronze Medal";
            pq.pop();
        }
        int rank = 4;
        while (!pq.empty()) {
            ans[pq.top().second] = to_string(rank);
            pq.pop();
            rank++;
        }
        return ans;
    }
};