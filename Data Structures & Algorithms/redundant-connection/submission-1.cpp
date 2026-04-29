class Solution {
public:
     int find_ultimate_parent(int x){
        if(parent[x]!=x){
            parent[x]=find_ultimate_parent(parent[x]);
        }
        return parent[x];
     }
     bool unite(int x,int y){
        int ultimate_parent_x=find_ultimate_parent(x);
        int ultimate_parent_y=find_ultimate_parent(y);
        if(ultimate_parent_x==ultimate_parent_y){
            return false;  //no merge required
        }
        if(rnk[ultimate_parent_x]<rnk[ultimate_parent_y]){
            parent[ultimate_parent_x]=ultimate_parent_y;
        }
        else if(rnk[ultimate_parent_x]>rnk[ultimate_parent_y]){
            parent[ultimate_parent_y]=ultimate_parent_x;
        }
        else{ //rank[ultimate_parent_x]==rank[ultimate_parent_y]
        parent[ultimate_parent_y]=ultimate_parent_x;
        rnk[ultimate_parent_x]++;

        }
        return true;
        
     }

public:
vector<int> parent;
vector<int>rnk;

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        rnk.resize(n+1,0);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        for(auto e:edges){
            if(unite(e[0],e[1])==false){
                return e;
            }
        }
        return {};
    }
};
