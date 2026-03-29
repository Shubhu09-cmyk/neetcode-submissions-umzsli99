class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for(string& str : strs){
            result+=to_string(str.size())+"#"+str;    //O(n)
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
       
        int i=0;
        
        while(i<s.size()){
                int j=i;
                //finding #
                while(s[j]!='#'){
                    j++;
                }
                //extract length
               int len=stoi(s.substr(i,j-i));
                //extracting string
              string str=s.substr(j+1,len);
                result.push_back(str);

                //movement of i for another word  in vector
                i=j+1+len;


        }
return result;
    }
};
