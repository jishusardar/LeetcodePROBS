class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<vector<int>>adj(num);
        vector<int>count(num,0);
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            count[pre[i][0]]++;
        }
        queue<int>q;
        for(int i=0;i<num;i++){
            if(!count[i])
            q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            num--;
            for(int i=0;i<adj[node].size();i++){
                count[adj[node][i]]--;
                if(!count[adj[node][i]])
                q.push(adj[node][i]);
            }
        }
        if(num)
        return 0;
        return 1;
    }
};