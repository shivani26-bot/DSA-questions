class Solution {
public:
struct trieNode{
    bool isEndOfWord;
    trieNode* children[26];
    int countPrefix;
};
trieNode* getTrieNode(){
    trieNode* newNode= new trieNode();
    for(int i=0;i<26;i++){
        newNode->children[i]=NULL;
    }
    newNode->isEndOfWord=false;
    newNode->countPrefix=0;
    return newNode;
}
void insert(trieNode* pCrawl, string word){
    for(auto ch: word){
        int idx=ch-'a';
        if(!pCrawl->children[idx]){
            pCrawl->children[idx]=getTrieNode();
           
        }
        pCrawl=pCrawl->children[idx];
         pCrawl->countPrefix+=1;
    }
    pCrawl->isEndOfWord=true;
}
int search(trieNode* pCrawl, string pref){


for(auto ch: pref){
    int idx=ch-'a';
    if(!pCrawl->children[idx]){
      return 0;
    }
    pCrawl=pCrawl->children[idx];
}
return pCrawl->countPrefix;
}
    int prefixCount(vector<string>& words, string pref) {
    //     int count = 0;
    // for (const string& word : words) {
    //     if (word.find(pref) == 0) { 
    //         count++;
    //     }
    // }
    // return count;
trieNode* root= getTrieNode();
    for(int i=0;i<words.size();i++){
        insert(root,words[i]);
    }

int result=search(root,pref);
    return result;
    }
};