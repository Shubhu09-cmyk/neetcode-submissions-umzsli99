class Solution {
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

    }
};
