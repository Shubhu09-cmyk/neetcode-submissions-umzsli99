/*
class Solution {
public:
        int m,n;
        vector<vector<int>> directions={{0,1},{-1,0},{1,0},{0,-1}};
    bool find(vector<vector<char>>& board,int i,int j, string& word,int idx){
        if(idx>=word.length()){
            return true;
        }
        //if(i<0 || j<0 || i>=m || j>=n || board[i][j]!=word[idx] || board[i][j]=='#'){
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]!=word[idx] ){   //# can be trhe part of the grid also and previous condition fulfills it
             return false;
        }
        char temp=board[i][j];
        board[i][j]='#';
        for(auto& dir:directions){
            int i_=i+dir[0];
            int j_=j+dir[1];
            if(find(board,i_,j_,word,idx+1)){
                board[i][j]=temp;  // not necessary
            return true;
            }
        }
         board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
      m=board.size();
      n=board[0].size();
     if(m*n<word.length()) return false;
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==word[0] && find(board,i,j,word,0))  //word index 0{
            return true;
        
        }
     }
     return false;
    }
};
*/

class Solution { 
public:
   int m,n;
    vector<vector<int>> dirs={{-1,0},{1,0},{0,1},{0,-1}};
    bool backtrack(vector<vector<char>>& board, string word,int idx,int i,int j){
        
        //check invalid
        if(i<0||j<0||i>=n||j>=m||board[i][j]!=word[idx]) return false;

        if(idx==word.size()-1) {
            return true;
        }
        
        char temp=board[i][j];
        board[i][j]='#';
        for(auto& dir:dirs){
            int nx=i+dir[0];
            int ny=j+dir[1];
            if(backtrack(board,word,idx+1,nx,ny)){
                board[i][j]=temp;
                return true;
            }
        }
        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        if(word.size()>n*m) return false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && backtrack(board,word,0,i,j)) return true;
            }
        }
       return false; 
    }
};
