// character by character match
// character by character search
// bad bets b.ts
struct Dictionary {
    Dictionary* children[26];
    bool isEndOfWord=false;
bool characterExist(char ch){
return (children[ch-'a']!=NULL);
}

void insertCharacter(char ch, Dictionary* root){
    children[ch-'a']=root;
}
Dictionary* moveNext(char ch){
    return children[ch-'a'];
}
void setEnd(){
    isEndOfWord=true;
}
bool endFlag(){
    return isEndOfWord;
}
};


class WordDictionary {
    Dictionary* root;
public:
    WordDictionary() {
      root= new Dictionary();  
    }
    
    void addWord(string word) {
        Dictionary* node= root;
        for(int i=0;i<word.size();i++){
            if(!node->characterExist(word[i])){
               node->insertCharacter(word[i], new Dictionary());
            }
            node=node->moveNext(word[i]);
        }
node->setEnd();
    }
    
    bool searchUtil(Dictionary* root, string word) {
         Dictionary* node= root;
        for(int i=0;i<word.size();i++){
            if(word[i]=='.') {
                for(int j=0;j<26;j++){
                    if(node->children[j]!=NULL){
                        if(searchUtil(node->children[j],word.substr(i+1)))
                    return true;
                    } }
                    return false;
               
   
                }
else if(!node->characterExist(word[i])) return false;
node=node->moveNext(word[i]);
        }
        return node->endFlag();
    }
    bool search(string word){
        return searchUtil(root,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */