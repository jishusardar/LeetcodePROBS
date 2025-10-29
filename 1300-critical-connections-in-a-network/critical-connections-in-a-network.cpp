class Solution {
public:
    void DFS(int node,int parent,vector<vector<int>>&adj,vector<int>&disc,vector<int>&low,vector<vector<int>>&bridge,int count,vector<bool>&visited){
        disc[node]=low[node]=count;
        visited[node]=1;
        for(int i=0;i<adj[node].size();i++){
            int neigh=adj[node][i];
            if(neigh==parent)
            continue;
            else if(visited[neigh])
            low[node]=min(low[node],low[neigh]);
            else{
                count++;
                DFS(neigh,node,adj,disc,low,bridge,count,visited);
                if(disc[node]<low[neigh]){
                    bridge.push_back({node,neigh});
                }
                low[node]=min(low[node],low[neigh]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>disc(n);
        vector<int>low(n);
        vector<vector<int>>bridge;
        int count=0;
        vector<bool>visited(n,0);
        DFS(0,-1,adj,disc,low,bridge,count,visited);
        return bridge;
    }
};