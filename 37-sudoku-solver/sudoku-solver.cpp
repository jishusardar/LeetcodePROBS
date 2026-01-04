class Solution {
public:
    bool check(int num,int i,int j,vector<vector<char>>& board)
    {
        char c=num+'0';
        //same row
        for(int k=0;k<9;k++){
            if(board[k][j]==c)
            return 0;
        }
        //same colmn
        for(int k=0;k<9;k++){
            if(board[i][k]==c)
            return 0;
        }
        //same box
        int row=i/3*3,colm=j/3*3;
        for(int k=0;k<3;k++){
            for(int l=0;l<3;l++){
                if(board[row+k][colm+l]==c)
                return 0;
            }
        }
        return 1;
    }
    bool sudoku(int i,int j,vector<vector<char>>& board){
        if(i==9)
        return 1;
        if(j==9)
        return sudoku(i+1,0,board);
        if(board[i][j]!='.')
        return sudoku(i,j+1,board);
        for(int k=1;k<=9;k++){
            if(check(k,i,j,board)){
                board[i][j]=k+'0';
                if(sudoku(i,j+1,board))
                return 1;
                board[i][j]='.';
            }
        }
        return 0;
    }
    void solveSudoku(vector<vector<char>>& board) {
        sudoku(0,0,board);
    }
};