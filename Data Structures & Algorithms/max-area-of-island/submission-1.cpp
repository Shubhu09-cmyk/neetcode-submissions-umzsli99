class Solution {
public:
    int dfs(int i,int j,int n,int m,vector<vector<int>>& grid){
        //base condition
        if(i<0||j<0||i>=n||j>=m||grid[i][j]==0){
            return 0;
        }
        grid[i][j]=0;  //mark as visited
        return 1+dfs(i-1,j,n,m,grid)+//top.  1 added as adding source node also as others are neighbor node
        dfs(i+1,j,n,m,grid)+//bottom
        dfs(i,j-1,n,m,grid)+//left
        dfs(i,j+1,n,m,grid);//right
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int area=dfs(i,j,n,m,grid);
                    maxArea=max(area,maxArea);
                }
            }
        }
        return maxArea;
    }
};
