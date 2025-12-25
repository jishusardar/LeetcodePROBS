class Solution {
public:
     bool check(int n,int i,int j,vector<string>&Board)
     {
        int row=i,colm=j;
        while(row>-1&&colm>-1){
            if(Board[row][colm]=='Q')
            return 0;
            row--,colm--;
        }
        row=i,colm=j;
        while(row>-1&&colm<n){
            if(Board[row][colm]=='Q')
            return 0;
            row--,colm++;
        }
        return 1;
     }
     void place(int row,int n,vector<vector<string>>&ans,vector<string>&Board,vector<bool>&colm)
     {
        if(row==n){
            ans.push_back(Board);
            return;
        }
        for(int j=0;j<n;j++){
            if(!colm[j]&&check(n,row,j,Board)){
                colm[j]=1;
                Board[row][j]='Q';
                place(row+1,n,ans,Board,colm);
                colm[j]=0;
                Board[row][j]='.';
            }
        }
     }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>Board(n);
        vector<bool>colm(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            Board[i].push_back('.');
        }
        place(0,n,ans,Board,colm);
        return ans;
    }
};