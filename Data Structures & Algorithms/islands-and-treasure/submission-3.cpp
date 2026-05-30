/*
class Solution {
public:
    //space O(nxm) time O(nxm)
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> que;  //i,j
        //pushing multi source treasure(0)
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                que.push({i,j});
                }
            }
        }

        vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
      while(!que.empty()){
        int i=que.front().first;   // use auto [i,j]=que,front(). and const int INF = 2147483647;
        int j=que.front().second;
        que.pop();
        
        for(auto it:directions){
            int ni=i+it[0];
            int nj=j+it[1];
            if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]==2147483647){
                grid[ni][nj]=grid[i][j]+1;
                que.push({ni,nj});
            }
        }
      }  
    }
};

*/


class Solution {
public:
    //space O(nxm) time O(nxm)
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> qu;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) qu.push({i,j});
            }
        }
            vector<pair<int,int>> dir={{0,-1},{-1,0},{0,1},{1,0}};
            while(!qu.empty()){
                auto [i,j]=qu.front();
                qu.pop();
                for(auto& [x,y]: dir){
                   int ni=i+x;
                   int nj=j+y;
                    if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]==2147483647){
                        grid[ni][nj]=grid[i][j]+1;
                        qu.push({ni,nj});
                    
                }
            }
        }
    }
    };
    
