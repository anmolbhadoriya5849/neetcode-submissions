class Solution {
public:

    void dfs(vector<vector<int>>& adj, vector<int>& visited, int neigh){
        if(visited[neigh]) return;
        visited[neigh] = true;
        for(auto x : adj[neigh]){
            dfs(adj, visited, x);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        vector<int> visited(n,0);

        int ans = 0;

        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                dfs(adj, visited, i);
            }
        }

        return ans;
    }
};
