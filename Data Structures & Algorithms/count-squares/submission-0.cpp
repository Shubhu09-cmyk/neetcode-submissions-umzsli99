class CountSquares {
public:

//space O(n)
/*
Function	Time	Space
add()	O(1) average	
count()	O(k) average, O(n) worst	
Total storage		O(n)
*/
unordered_map<int,unordered_map<int,int>> cnt;
    CountSquares() {
        
        
    }
    
    void add(vector<int> point) {
        int x=point[0];
        int y=point[1];
        cnt[x][y]++;
        
    }
    
    int count(vector<int> point) {
        int x=point[0];
        int y=point[1];
        int ans=0;
        //check all points having same x co-ordinates
        for(auto& [ny,freq]:cnt[x]){  //x->ny,freq
            if(ny==y) continue;//same point invalid
            int d=abs(ny-y);
            //check left
            ans+=freq*cnt[x-d][ny]*cnt[x-d][y];
            //check right
            ans+=freq*cnt[x+d][ny]*cnt[x+d][y];//keep y constant
        }
        return ans;
    }
};
