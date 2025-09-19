class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& rela, vector<int>& time) {
        vector<vector<int>>Adj(n);
        for(int i=0;i<rela.size();i++){
            Adj[rela[i][0]-1].push_back(rela[i][1]-1);
        }
        vector<int>indegree(n,0);
        for(int i=0;i<Adj.size();i++){
            for(int j=0;j<Adj[i].size();j++)
            indegree[Adj[i][j]]++;
        }
        queue<int>q;
        vector<int>ct(n,0);
        for(int i=0;i<n;i++){
            if(!indegree[i])
            q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i=0;i<Adj[node].size();i++){
                indegree[Adj[node][i]]--;
                if(!indegree[Adj[node][i]])
                q.push(Adj[node][i]);
                ct[Adj[node][i]]=max(ct[node]+time[node],ct[Adj[node][i]]);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,ct[i]+time[i]);
        }
        return ans;
    }
};