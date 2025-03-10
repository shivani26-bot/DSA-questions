class Solution {
public:
vector<string>result;
int m, n;
vector<pair<int,int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
struct trieNode{
    trieNode* children[26];
    bool isEndOfWord;
    string word;//when we reach the endofword, we store the word whose end is reached
};
trieNode* getTrieNode(){
    trieNode* newNode=new trieNode();
    for(int i=0;i<26;i++){
        newNode->children[i]=NULL;
    }
    newNode->isEndOfWord=false;
    newNode->word="";
    return newNode;
}

void insert(trieNode* pCrawl, string str){
    for(auto ch:str){
        int idx=ch-'a';
        if(!pCrawl->children[idx]){
            pCrawl->children[idx]=getTrieNode();
          
            
        }
          pCrawl=pCrawl->children[idx];
    }
    pCrawl->isEndOfWord=true;
    pCrawl->word=str;
}

void dfs(vector<vector<char>>& board, int i, int j, trieNode* pCrawl){
if(i<0 || i>=m || j<0 ||j>=n ||board[i][j]=='$' || pCrawl->children[board[i][j]-'a']==NULL) return ;


    pCrawl=pCrawl->children[board[i][j]-'a'];
    
if(pCrawl->isEndOfWord==true){
    result.push_back(pCrawl->word);
    pCrawl->isEndOfWord=false;
}
    char temp=board[i][j];
    board[i][j]='$';//mark visited;
    //traverse left, right, up and down
    for(auto it: directions){
        int new_i= i+it.first;
        int new_j= j+it.second;
        dfs(board, new_i, new_j, pCrawl);
    }
    board[i][j]=temp;//marking unvisited

}
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // insert each word from the words array into the trie 
        trieNode* root= getTrieNode();
        for(int i=0;i<words.size();i++){
            insert(root,words[i]);
        }
       m=board.size();
      n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                char ch=board[i][j];
                if(root->children[ch-'a']!=NULL){
                   dfs(board, i, j,root);
                }
            }
        }
        return result;
    }
};


// ex: bat, bate, if endofword is found true for bat then don't stop iterate further as bate is present