class Solution {
public:

    bool cycledfs(int src, vector<bool>& vis,
                  vector<bool>& recpath,
                  vector<vector<int>>& edge) {

        vis[src] = true;
        recpath[src] = true;

        for (int i = 0; i < edge.size(); i++) {

            int v = edge[i][0];
            int u = edge[i][1];

            if (u == src) {

                if (!vis[v]) {

                    if (cycledfs(v, vis, recpath, edge)) {
                        return true;
                    }

                }
                else if (recpath[v]) {
                    return true;
                }
            }
        }

        recpath[src] = false;

        return false;
    }


    void topo(int src, stack<int>& s,
              vector<bool>& vis,
              vector<vector<int>>& edge) {

        vis[src] = true;

        for (int i = 0; i < edge.size(); i++) {

            int v = edge[i][0];
            int u = edge[i][1];

            if (u == src && !vis[v]) {
                topo(v, s, vis, edge);
            }
        }

        s.push(src);
    }


    vector<int> findOrder(int n, vector<vector<int>>& edge) {

        vector<bool> vis(n, false);
        vector<bool> recpath(n, false);

        vector<int> ans;

        // Cycle detection
        for (int i = 0; i < n; i++) {

            if (!vis[i]) {

                if (cycledfs(i, vis, recpath, edge)) {
                    return {};
                }
            }
        }

        stack<int> s;

        // Reset visited
        vis.assign(n, false);

        // Topological sort
        for (int i = 0; i < n; i++) {

            if (!vis[i]) {
                topo(i, s, vis, edge);
            }
        }

        // Stack -> answer
        while (s.size() > 0) {

            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};