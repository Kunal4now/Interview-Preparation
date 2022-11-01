#include "bits/stdc++.h"

void dfs(int v, vector<int> &path, vector<bool> &vis, vector<vector<int>> &adj) {
    vis[v] = true;
    path.push_back(v);
    for (auto u: adj[v]) {
        if (!vis[u]) {
            dfs(u, path, vis, adj);
        }
    }
}

vector<int> restoreArray(int n, vector<vector<int>> &arr) {
    int mx = 0;
    for (int i = 0; i < arr.size(); i++) {
        mx = max({mx, arr[i][0], arr[i][1]});
    }
    
    vector<int> path;
    vector<bool> vis(mx + 1, false);
    
    vector<vector<int>> adj(mx + 1);
    for (int i = 0; i < arr.size(); i++) {
        adj[arr[i][0]].push_back(arr[i][1]);
        adj[arr[i][1]].push_back(arr[i][0]);
    }
    
    int start = 1;
    
    for (int i = 1; i <= mx; i++) {
        if (adj[i].size() == 1) {
            start = i;
            break;
        } 
    }

    dfs(start, path, vis, adj);
    return path;
}

/*
https://www.codingninjas.com/codestudio/problems/restore-array_1404537?topList=mohammad-fraz-dsa-sheet-problems&leftPanelTab=0
*/

/*
APPROACH:
=> Do a DFS after making adjecency
*/
