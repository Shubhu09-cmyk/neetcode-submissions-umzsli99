class Solution {
public:
//time O(n). space O(1)
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    bool a=false,b=false,c=false;//can use vector<bool> match(3,false)
    for(auto& t:triplets){
        //ignore invalid triplets
        if(t[0]>target[0] || t[1]>target[1] || t[2]>target[2] ) continue;
    
    if(t[0]==target[0]) a=true;   //for(int i=0;i<3;i++) if(t[i]==target[i]) match[i] =true;  
    if(t[1]==target[1]) b=true;   
    if(t[2]==target[2]) c=true;
    
    }
    return a && b && c;                 //return match[0] &&match[1] && match[2]

    }
};


