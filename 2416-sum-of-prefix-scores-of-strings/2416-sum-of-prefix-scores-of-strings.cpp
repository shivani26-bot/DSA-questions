struct trieNode{
    int countP=0;
    trieNode* children[26];
};
class Solution {
public:
 trieNode* getTrieNode(){
    trieNode* newNode= new trieNode();
   for(int i=0;i<26;i++){
    newNode->children[i]=NULL;
   }
   newNode->countP=0;
   return newNode;
 }
 void insert(string &word, trieNode* root){
    trieNode* temp=root;
    for(char &ch: word){
        int idx=ch-'a';
        if(!temp->children[idx]){
            temp->children[idx]= getTrieNode();
        }
        temp->children[idx]->countP+=1;
        temp=temp->children[idx];
    }
 }
 int getScore(string& word, trieNode* root){
    trieNode* temp=root;
    int score=0;
    for(auto ch: word){
        int idx=ch-'a';
        score+=temp->children[idx]->countP;
        temp=temp->children[idx];
    }
    return score;
 }
    vector<int> sumPrefixScores(vector<string>& words) {
    //we must know , which prefix has occured how many times 
// store all the words in trie data structure 
// also maintain how many times a prefix has occured 
// for ex: abc -> prefixes are a, ab, abc
            // ab-> prefixes are a, ab
            // bc-> prefixes are b, bc
            // b-> prefixes are b
        // store the count of all the prefixes appeared in a word 
        // can keep a variable count in trie node, which will maintain the count of occurence of a particular letter 
        // for ex:abc
        // a->count=1
        // ab-> count=1
        // abc-> count=1
        // ab
        // a->count=2
        // ab->count=2
        // bc
        // b->count=1
        // bc->count=1
        // b
        // b->count=2 
int n=words.size();
trieNode* root= getTrieNode();
for(auto word: words){
    insert(word,root);
}
vector<int>result(n);
for(int i=0;i<n;i++){
    result[i]= getScore(words[i],root);
}
return result;
    }
};