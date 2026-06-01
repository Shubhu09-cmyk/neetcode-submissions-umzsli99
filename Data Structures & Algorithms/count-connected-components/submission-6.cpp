
/*class Solution {
    private:
    int find_parent(int x){
        if(parent[x]!=x){
            parent[x]=find_parent(parent[x]);  //path compression
        }
        return parent[x];
    }
    bool unite(int x,int y){
        int ultimate_px=find_parent(x);
        int ultimate_py=find_parent(y);
        if(ultimate_px==ultimate_py){
            return false;  //merge can't happen
        }
        if(rank[ultimate_px]<rank[ultimate_py]){
            parent[ultimate_px]=ultimate_py;
        }
        else if(rank[ultimate_px]>rank[ultimate_py]){
            parent[ultimate_py]=ultimate_px;
        }
        else{
            parent[ultimate_py]=ultimate_px;
            rank[ultimate_px]++;
        }
        return true;
    }

public:  //union find disjoint set
    vector<int> parent;
    vector<int>rank;  //use rnk
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        int components=n;
        for(auto& edge:edges){
            if(unite(edge[0],edge[1])==true){
                components--;
            }
        }
        return components;

        /* time.  O(N+E⋅α(N))
🧠 Space Complexity. O(N)
*/
class Solution {
           /* time.  O(N+E⋅α(N))
🧠 Space Complexity. O(N)
*/

  public:
  vector<int> parent;
  vector<int> rank;
    int find_ultimate_parent(int x){
        if(parent[x]==x) return x;
        return parent[x]=find_ultimate_parent(parent[x]);
    }
    
    bool unite(int x,int y){
        int ulP_x=find_ultimate_parent(x);
        int ulP_y=find_ultimate_parent(y);
        if(ulP_x==ulP_y) return false;//cycle so merge not possible
        if(rank[ulP_x]>rank[ulP_y]) parent[ulP_y]=ulP_x;
        else if(rank[ulP_x]<rank[ulP_y]) parent[ulP_x]=ulP_y;
        else{//both rank equal
            parent[ulP_x]=ulP_y;
            rank[ulP_y]++;
        }
        return true;
    }
  
    int countComponents(int V, vector<vector<int>>& edges) {
        // code here
        parent.resize(V);
        rank.resize(V,0);
        for(int i=0;i<V;i++) parent[i]=i;
        int components=V;
        for(auto& v:edges){
            if(unite(v[0],v[1])==true) components--;
        }
        return components;
    

    }
};

