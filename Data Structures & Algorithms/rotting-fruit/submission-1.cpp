class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        queue<pair<pair<int,int>,int>> que;
        //pushing multi source in que
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                que.push({{i,j},0});   //i,j and time=0 for sources
                visited[i][j]=true;  //mark it as visited
                }
            }
        }
        while(que.size()>0){
            int i=que.front().first.first;
            int j=que.front().first.second;
            int t=que.front().second;
            que.pop();
            ans=max(ans,t);
            //visiting top nbr of rotten source
            if(i-1>=0 && grid[i-1][j]==1 && visited[i-1][j]==false){  //i include 0
                //grid[i-1][j]=2;
                que.push({{i-1,j},t+1});
                visited[i-1][j]=true;
            }
                       //visiting bottom nbr of rotten source
            if(i+1<n && grid[i+1][j]==1 && visited[i+1][j]==false){
                //grid[i+1][j]=2;
                que.push({{i+1,j},t+1});
                visited[i+1][j]=true;
            }
                       //visiting left nbr of rotten source
            if(j-1>=0 && grid[i][j-1]==1 && visited[i][j-1]==false){
                //grid[i][j-1]=2;
                que.push({{i,j-1},t+1});
                visited[i][j-1]=true;
            }
                       //visiting right nbr of rotten source
            if(j+1<m && grid[i][j+1]==1 && visited[i][j+1]==false){
                //grid[i][j+1]=2;
                que.push({{i,j+1},t+1});
                visited[i][j+1]=true;
            } 
        }
        //check for fresh orange
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]!=true){
                    return -1;
                }
            }
        }
        return ans;
        
    }
};
