
struct trieNode{
    trieNode* children[26];
    bool isEndOfWord=false; //marked true if a particular cahracter is end of the word
    bool characterExist(char ch){
        return (children[ch-'a']!=NULL);
    }
    void insertCharacter(char ch,trieNode* root){
        children[ch-'a']=root;
    }
    trieNode* moveNext(char ch){
        return  children[ch-'a'];
    }
    void setEnd(){
        isEndOfWord=true;
    }
    bool endFlag(){
        return isEndOfWord;
    }
};
class Trie {
    trieNode* root;
public:
    Trie() {
       root=new trieNode();
    }
    
    void insert(string word) {
       trieNode* node= root;
        for(int i=0;i<word.size();i++){
             if(!node->characterExist(word[i])){
            node->insertCharacter(word[i],new trieNode());
        }
        node=node->moveNext(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
       trieNode* node=root;
       for(int i=0;i<word.size();i++){
        if(!node->characterExist(word[i])) return false;
        node=node->moveNext(word[i]);
       }
       return node->endFlag();
    }
    
    bool startsWith(string prefix) {
        trieNode* node=root;
        for(int i=0;i<prefix.size();i++){
            if(!node->characterExist(prefix[i])) return false;
            node=node->moveNext(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */