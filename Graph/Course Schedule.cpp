class Solution {
public:
    stack<int> st;
    bool vis[2001];
    void topoSort(int v, vector<vector<int>> &adj) {
        vis[v] = true;
        for (auto &u: adj[v]) {
            if (!vis[u]) {
                topoSort(u, adj);
            }
        }
        st.push(v);
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        memset(vis, false, sizeof(vis));
            
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                topoSort(i, adj);
            }
        } 
        
        vector<int> nodes;
        while (!st.empty()) {
            nodes.push_back(st.top());
            cout << nodes.back() << " ";
            st.pop();
        }
    
        vector<int> idx(nodes.size());
        for (int i = 0; i < nodes.size(); i++) {
            idx[nodes[i]] = i;
        }
        
        bool ok = true;
        for (int i = 0; i < prerequisites.size(); i++) {
            ok &= (idx[prerequisites[i][1]] < idx[prerequisites[i][0]]);
        }
        
        return ok;
    }
};
