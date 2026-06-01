class Solution {
public://Time: O(N × L × 26). //time O(NL). space O(N)
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word_set(wordList.begin(),wordList.end()); //populating all words in set
        if(!word_set.count(endWord)) {//edge case
            return 0;
        }
        queue<pair<string,int>> qu;//word and level
        qu.push({beginWord,1});
        word_set.erase(beginWord);
        while(!qu.empty()){
            auto [word,level]=qu.front();//copy while popping
            qu.pop();
            //cat
            for(int i=0;i<word.length();i++){
                char original=word[i];//let take c
                for(char j='a'; j<='z';j++){// aat,bat.....zat
                        if (j == original) continue;//cat again then skip it
                        word[i]=j;
                        if(word==endWord) return level+1;      //if word matches while generation
                        if(word_set.count(word)==true){//if word available in word set
                        qu.push({word,level+1});
                        word_set.erase(word);
                        }
                        }
                        word[i]=original;
            }
        }
        return 0;
    }
};
