class Solution {
public:
//      words[0]=abc-> all prefix: a, ab, abc find score of each prefix of abc, and sum them
//         sum of scores of every non-empty prefix of words[i]
//         abc,ab,a
// scores:  1, 2, 2=> 2+2+1=5
// words[0]=abc= ans[0]= 5
// words[1]=ab-> all prefix: a, ab
//        a, ab
// scores:2+2=4
// words[2]=bc-> all prefix: b, bc
//        b, bc
// scores:2+1=4  b is present as prefix in bc,b
// store all the prefixes of each word[i];
// insert all the words from the words array into the trie 
// kaun sa prefix kitni baar aaya hai ye pta hona chahiye 
struct trieNode{
    int countPrefix=0;
    trieNode* children[26];
};

trieNode* getTrieNode(){
    trieNode* newNode= new trieNode();
    for(int i=0;i<26;i++){
        newNode->children[i]=NULL;
    }
newNode->countPrefix=0;
    return newNode;
}
int getScore(string& word, trieNode* pCrawl){
  int score=0;
  for(auto ch: word){
    int idx= ch-'a';
    score+= pCrawl->children[idx]->countPrefix;
    pCrawl= pCrawl->children[idx];
  }
  return score;
}
void insert(string word, trieNode* pCrawl){

    for(char ch: word){
        int idx= ch-'a';
        if(pCrawl->children[idx]==NULL){
       pCrawl->children[idx]= getTrieNode();

        }
        pCrawl->children[idx]->countPrefix+=1;
        pCrawl=pCrawl->children[idx];
    }
}
    vector<int> sumPrefixScores(vector<string>& words) {
trieNode* root= getTrieNode();
for(int i=0;i<words.size();i++){
    string word= words[i];
insert(word, root);
}
vector<int>result(words.size());
for(int i=0;i<words.size();i++){
    result[i]= getScore(words[i],root);
}
return result;
    }
};