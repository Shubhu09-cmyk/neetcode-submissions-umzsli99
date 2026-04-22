class trieNode{
    public:
    trieNode *children[26];
    bool isTerminal;

    trieNode(){
        isTerminal=false;
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
    }
};

class PrefixTree {
private:
    trieNode* root;
public:
    //constructor
    PrefixTree() {
        root=new trieNode();    
    }
    
    void insert(string word) {
        trieNode* crawl=root;
        for(char ch:word){
            int index=ch-'a';  //char to index
            if(crawl->children[index]==nullptr){
                crawl->children[index]=new trieNode();        
            }
           crawl=crawl->children[index];
        }
        crawl->isTerminal=true;
        
    }
    
    bool search(string word) {
        trieNode* crawl=root;
        for(char ch:word){
            int index=ch-'a';
            if(crawl->children[index]==nullptr){
                return false;
            }
            crawl=crawl->children[index];
        }
        return crawl->isTerminal==true;
    }
    
    bool startsWith(string prefix) {
        trieNode* crawl=root;
        for(char ch:prefix){
            int index=ch-'a';
            if(crawl->children[index]==nullptr){
                return false;
            }
            crawl=crawl->children[index];
        }
        return true;
    }
};
