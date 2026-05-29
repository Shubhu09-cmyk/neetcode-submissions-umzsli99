class trieNode{
public:
    trieNode* children[26];
    bool isTerminal;
    string word;
 
    trieNode(){
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
        word="";
        isTerminal=false;
    }
};

class Solution {
public:
    int n,m;
    vector<string>result;
    vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};

    void insert(trieNode* root,string& word){
    trieNode* crawl=root;
    for(char ch: word){
        if(crawl->children[ch-'a']==nullptr) {
            crawl->children[ch-'a']=new trieNode();
        }
        crawl=crawl->children[ch-'a'];
    }
    crawl->isTerminal=true;
    crawl->word=word;

}

    void dfs(vector<vector<char>>& board,trieNode* root,int i,int j){
        if(i<0||j<0||i>=n||j>=m||board[i][j]=='#'||root->children[board[i][j]-'a']==nullptr) return;
        root=root->children[board[i][j]-'a'];

        //if word found
        if(root->isTerminal==true){
            result.push_back(root->word);
            root->isTerminal=false;//to avoid duplicates
        }
        char temp=board[i][j];
        board[i][j]='#';
        //explore all the directions
        for(auto& d:dir){
            int nx=i+d[0];
            int ny=j+d[1];
            dfs(board,root,nx,ny);
        }
        board[i][j]=temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty() || board[0].empty()) return {};
        n=board.size();
        m=board[0].size();
        trieNode* root=new trieNode();
        
        //insert words in trie
        for(string& word:words){
        insert(root,word);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char ch=board[i][j];
                if(root->children[ch-'a']!=nullptr){
                    dfs(board,root,i,j);
                }
            }
        }
        return result;
    }
};
