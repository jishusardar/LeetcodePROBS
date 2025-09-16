class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        queue<pair<int,int>>q;
        int n=isConnected.size();
        int m=isConnected[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j]==1){
                    q.push({i,j});
                    count++;
                    while(!q.empty()){
                        int ni=q.front().first;
                        int nj=q.front().second;
                        isConnected[ni][nj]=0;
                        q.pop();
                        for(int k=0;k<m;k++){
                            if(isConnected[ni][k]==1){
                                isConnected[ni][k]=0;
                                q.push({k,ni});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};