class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //greedy math approach 
        unordered_map<char,int> freq;
        for(char& c : tasks){ //calculate frequency
            freq[c]++;
        }
        //calc max freq
        int maxFreq=0;
        for( auto& c : freq){
            maxFreq=max(maxFreq,c.second);
        }
        //calc maxCount
        int maxCount=0;
        for(auto& c : freq){
            if(maxFreq==c.second){
                maxCount++;
            }
        }
        //apply formula
        int result=(maxFreq-1)*(n+1)+maxCount;
        return max((int)tasks.size(),result);
    }
};
