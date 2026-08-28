class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> graph(V);
        vector<int> indegree(V, 0);

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            graph[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        for(int i = 0; i < V; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            ans.push_back(u);

            for(int i = 0; i < graph[u].size(); i++){
                int v = graph[u][i];

                indegree[v]--;

                if(indegree[v] == 0)
                    q.push(v);
            }
        }

        return ans;
    }
};