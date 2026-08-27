class Solution {
public:

    void solveDFS(vector<vector<int>>& adj, vector<bool>& vis, vector<int>& ans, int vertex){

        // Current vertex ko visited mark karo
        vis[vertex] = true;

        // Answer mein add karo
        ans.push_back(vertex);

        // Current vertex ke saare neighbours check karo
        for(int neighbour : adj[vertex]){

            if(!vis[neighbour]){
                solveDFS(adj, vis, ans, neighbour);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {

        vector<int> ans;

        vector<bool> vis(adj.size(), false);

        // DFS 0 se start
        solveDFS(adj, vis, ans, 0);

        return ans;
    }
};