class Solution {
public:
    int rows[4]={-1,0,0,1};
    int colms[4]={0,-1,1,0};
    int n;
    int m;
    bool valid(int i,int j){
        return i>=0&&i<n&&j>=0&&j<m;
    }
    void solve(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O')
            q.push({i,0});
        }
        for(int i=1;i<board[0].size();i++){
            if(board[board.size()-1][i]=='O')
            q.push({board.size()-1,i});
        }
        for(int i=1;i<board.size();i++){
            if(board[i][board[0].size()-1]=='O')
            q.push({i,board[0].size()-1});
        }
        for(int i=1;i<board[0].size();i++){
            if(board[0][i]=='O')
            q.push({0,i});
        }
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            board[i][j]='V';
            for(int k=0;k<4;k++){
                if(valid(i+rows[k],j+colms[k])&&board[i+rows[k]][j+colms[k]]=='O'){
                    board[i+rows[k]][j+colms[k]]='V';
                    q.push({i+rows[k],j+colms[k]});
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='V')
                board[i][j]='O';
                else
                board[i][j]='X';
            }
        }
    }
};