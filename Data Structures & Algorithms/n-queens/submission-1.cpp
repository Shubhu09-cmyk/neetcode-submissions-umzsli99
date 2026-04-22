class Solution {
public:
bool isSafe(int n,int row,int col,vector<string>& board){
    for(int j=0;j<n;j++)//checking row, we can skip this also
    {
        if(board[row][j]=='Q') return false;
    }
    for(int j=0;j<row;j++)//checking column.  more optimal for(int j=0;j<row;j++)
    {
        if(board[j][col]=='Q') return false;
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){  //check left diagonal
        if(board[i][j]=='Q') return false;
    }
    for(int i=row,j=col;i>=0 && j<n;i--,j++){ //checking right diagonal
        if(board[i][j]=='Q') return false;
    }
    return true;
}

    void nQueens(int n,int row,vector<vector<string>>& ans,vector<string>& board){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafe(n,row,j,board)){
                board[row][j]='Q';
                nQueens(n,row+1,ans,board);
                board[row][j]='.';

            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        nQueens(n,0,ans,board);
        return ans;

        
    }
};
