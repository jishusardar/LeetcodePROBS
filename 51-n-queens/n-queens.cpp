class Solution {
public:
     void place(int row,int n,vector<vector<string>>&ans,vector<string>&Board,vector<bool>&colm,vector<bool>&Leftdig,vector<bool>&Rightdig)
     {
        if(row==n){
            ans.push_back(Board);
            return;
        }
        for(int j=0;j<n;j++){
            if(!colm[j]&&!Rightdig[j+row]&&!Leftdig[(n-1)+j-row]){
                colm[j]=1;
                Leftdig[(n-1)+j-row]=1;
                Rightdig[j+row]=1;
                Board[row][j]='Q';
                place(row+1,n,ans,Board,colm,Leftdig,Rightdig);
                colm[j]=0;
                Board[row][j]='.';
                Leftdig[(n-1)+j-row]=0;
                Rightdig[j+row]=0;
            }
        }
     }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>Board(n);
        vector<bool>colm(n);
        vector<bool>Leftdig(2*n-1,0);
        vector<bool>Rightdig(2*n-1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            Board[i].push_back('.');
        }
        place(0,n,ans,Board,colm,Leftdig,Rightdig);
        return ans;
    }
};