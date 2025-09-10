class Solution {
public:
    bool Detect(vector<vector<int>>&graph,vector<int>&color,int i)
    {
        queue<int>q;
        q.push(i);
        color[i]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i=0;i<graph[node].size();i++){
                if(color[graph[node][i]]==-1){
                    color[graph[node][i]]=!color[node];
                    q.push(graph[node][i]);
                }
                if(color[graph[node][i]]==color[node])
                return 0;
            }
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!Detect(graph,color,i))
                return 0;
            }
        }
        return 1;
    }
};