class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>Adj(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            Adj[i][i]=0;
        }
        for(int i=0;i<edges.size();i++){
            Adj[edges[i][0]][edges[i][1]]=edges[i][2];
            Adj[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(Adj[i][k]==INT_MAX)
                    continue;
                    if(Adj[k][j]==INT_MAX)
                    continue;
                    Adj[i][j]=min(Adj[i][j],Adj[i][k]+Adj[k][j]);
                }
            }
        }
        int nums=INT_MAX,ans=-1;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(Adj[i][j]!=INT_MAX&&Adj[i][j]<=distanceThreshold)
                count++;
            }
            if(count<nums){
                nums=count;
                ans=i;
            }
            else if(count==nums){
                ans=max(ans,i);
            }
        }
        return ans;
    }
};