struct Node{
    Node* links[26];
    bool flag=false;
    bool characterExists(char ch){
       return links[ch-'a'] != NULL;
    }
    void insertCharacter(char ch, Node*node){
        links[ch-'a']=node;
    }
    Node* moveNext(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool getFlag(){
        return flag;
    }
  };
class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(string word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->characterExists(word[i]))  node->insertCharacter(word[i],new Node());
            
              node=node->moveNext(word[i]);
        }
        node->setEnd();
    }
    string givePrefix(string word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(node->getFlag()){
                return word.substr(0,i);
            }
            else if(!node->characterExists(word[i])){
            return word;
            }
            node=node->moveNext(word[i]);
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie *obj= new Trie();
        for(int i=0;i<dictionary.size();i++){
            obj->insert(dictionary[i]);
        }
     
          sentence+= ' ';
          vector<string>words;
          string s;
          for(int i=0;i<sentence.length();i++){
              if(sentence[i]!=' '){
                  s+=sentence[i];
              }
              else{
                  words.push_back(s);
                  s="";
              }
          }
        //   for(auto& it: words){
        //       it= obj->givePrefix(it);
        //   }
        for(int i=0;i<words.size();i++){
            words[i]= obj->givePrefix(words[i]);
        }
          s="";
          s+=words[0];
          for(int i=1;i<words.size();i++){
              s+= ' '+ words[i];
          }
          return s;
    }
};