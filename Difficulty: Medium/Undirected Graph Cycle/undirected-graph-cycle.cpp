class Solution {
  public:

    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& visited){
        visited[node] = 1;

        for(int neighbour : adj[node]) {

            // Agar neighbour visit nahi hua
            if(!visited[neighbour]) {
                if(dfs(neighbour, node, adj, visited))
                    return true;
            }

            // Visited hai aur parent nahi hai
            else if(neighbour != parent) {
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(V, 0);

        // Graph disconnected ho sakta hai
        for(int i = 0; i < V; i++){

            if(!visited[i]) {
                if(dfs(i, -1, adj, visited))
                    return true;
            }
        }

        return false;
    }
};