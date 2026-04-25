class Solution {
public:
   vector<pair<int,int>> directions={{0,-1},{-1,0},{0,1},{1,0}};
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;    //edge case
        //solving using dfs
        int n=board.size(); //rows
        int m=board[0].size(); //col
        vector<vector<int>> vis(n,vector<int>(m,0));   //can be bool also

        //checking the 1st and rast row
        for(int i=0;i<m;i++){ 
           if(board[0][i]=='O'){//first row
            dfs(0,i,vis,board);
           }
           if(board[n-1][i]=='O'){//last row
           dfs(n-1,i,vis,board);
           }
        }
        //checking 1st and last column
        for(int i=0;i<n;i++){
            //1st column
            if(board[i][0]=='O'){//first col
                dfs(i,0,vis,board);
            }
            //last col
            if(board[i][m-1]=='O'){//last col
            dfs(i,m-1,vis,board);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(board[i][j]=='O' && vis[i][j]==0){
            board[i][j]='X';
        }
            }
        }
        
        
    }

    private:
     void dfs(int i, int j,vector<vector<int>>& vis,vector<vector<char>>& board){
        vis[i][j]=1;
        for(auto [x,y]:directions){
            int ni=i+x;
            int nj=j+y;
            if(ni>=0 && nj>=0 && ni<board.size() && nj<board[0].size() && vis[ni][nj]==0 && board[ni][nj]=='O'){
               dfs(ni,nj,vis,board) ;
            }
        }
    }
};
