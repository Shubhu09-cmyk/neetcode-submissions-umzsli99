class Solution {
private:
    vector<pair<int,int>> direction={{0,-1},{0,1},{1,0},{-1,0}};

    void dfs(int i,int j,vector<vector<bool>>& ocean,vector<vector<int>>& heights){
         ocean[i][j]=true;
        for(auto [x,y]:direction){
            int ni=i+x;
            int nj=j+y;
            if(ni>=0 && nj>=0 && ni<heights.size() && nj<heights[0].size() && heights[ni][nj] >= heights[i][j] && ocean[ni][nj]==false){
                dfs(ni,nj,ocean,heights);
            }
        }
    }
    public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //using dfs , can also be solved by bfs.  from neetcode sol only.
        int n=heights.size();  //size of rows
        int m=heights[0].size();  //size of columns
        vector<vector<bool>> pac(n,vector<bool>(m,false));//mark all pac false
        vector<vector<bool>> atl(n,vector<bool>(m,false)); //mark all atlantic false

        vector<vector<int>> res;

        //filling top and bottom of pac and atlantic accordingltt
        for(int i=0;i<m;i++){
            dfs(0,i,pac,heights);  //first row
            dfs(n-1,i,atl,heights);  //last row
        }
        //filling left and right of pac and atlantic accordingly
        for(int i=0;i<n;i++){
            dfs(i,0,pac,heights);
            dfs(i,m-1,atl,heights);
        }

        //if both intersects
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j] && atl[i][j]){
                    res.push_back({i,j});
                }
            }
        }
       return res; 
    }
    

};
