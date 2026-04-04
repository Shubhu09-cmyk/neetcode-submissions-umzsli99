class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
        
    }
    
    string get(string key, int timestamp) {
        if(!mp.contains(key)){
            return "";
        }
        int l=0;
        auto vec=mp[key];
        string res="";
        int r=vec.size()-1;
        while(l<=r){
          int mid=l+(r-l)/2;
            if(vec[mid].first<=timestamp){
                res=vec[mid].second;                
                 l=mid+1;
            }else{
               r=mid-1;
            }
            
        }
return res;
    }
};
