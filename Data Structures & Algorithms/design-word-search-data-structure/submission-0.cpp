class trieNode{
public:
    trieNode* children[26];
    bool isEnd;
    //construcror
    trieNode(){
        isEnd=false;
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
    }

};

class WordDictionary {
    private:
    trieNode* root;
public:
     //constructor
    WordDictionary() {
     root=new trieNode();
    }
    
    void addWord(string word) {
        trieNode* crawl=root;
        for(char ch:word){
            int index=ch-'a';
            if(crawl->children[index]==nullptr){
                crawl->children[index]=new trieNode();
            }
            crawl=crawl->children[index];
        }
        crawl->isEnd=true;
    }
    //create one function
    bool searchUtil(trieNode* root,int idx,string& word){
        trieNode* crawl=root;
        if(idx==word.length()){
            return crawl->isEnd;
        }

        int index=word[idx]-'a';
        //if normal character
        if(word[idx]!='.'){
            if(crawl->children[index]==nullptr){
                return false;
            }
        return searchUtil(crawl->children[index],idx+1,word);   
            
        }
        //.
        if(word[idx]=='.'){
            for(int i=0;i<26;i++){
                if(crawl->children[i]!=nullptr){
                    if(searchUtil(crawl->children[i],idx+1,word)){
                        return true;
                    }
                }
            }
         
        }
        return false;  
    }

    bool search(string word) {
       return searchUtil(root,0,word);
        
    }
};
