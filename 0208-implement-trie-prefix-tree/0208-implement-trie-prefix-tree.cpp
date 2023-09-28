struct Node {
    Node* links[26];
    bool flag=false;
    bool characterExist(char ch){
        return (links[ch-'a'] !=NULL);
    }
    void insertCharacter(char ch, Node* root){
        links[ch-'a']= root;
    }
    Node* moveNext(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
bool endFlag(){
return flag;
}

};
class Trie {
   Node* root; 
public:
    Trie() {
     root= new Node();
            }
    
    void insert(string word) {
        Node* node= root;
        for(int i=0;i<word.size();i++){
            if(!node->characterExist(word[i])){
                node->insertCharacter(word[i],new Node());
            }
            node = node->moveNext(word[i]);
        }
        node->setEnd();
            }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->characterExist(word[i])){
                return false;
            }
            node= node->moveNext(word[i]);
        }
        return node->endFlag();
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(int i=0;i<prefix.size();i++){
            if(!node->characterExist(prefix[i])){
                return false;
            }
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