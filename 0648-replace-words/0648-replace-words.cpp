class Solution {
public:
    // string replaceWords(vector<string>& dictionary, string sentence) {
    //     sentence+=' ';
    //     string result="",word="";

    //     set<string>st;
    //     for(auto i: dictionary) st.insert(i);

    //     for(auto it: sentence){
             
    //            if(it==' '){
    //               if(result.size()>0) result+=' ';
    //               string temp="";
    //               for(auto i: word){
    //                    temp+=i;
    //               if(st.find(temp)!=st.end()) break;
    //               }
    //            result+=temp;
    //           word="";
    //         }
    //      else   word+=it;
    //      }
    //     return result;
    // }




struct trieNode{
trieNode* children[26];
bool isEndOfWord;
};
trieNode* getTrieNode(){
    trieNode *newNode= new trieNode();
    newNode->isEndOfWord=false;
    for(int i=0;i<26;i++){
        newNode->children[i]=NULL;
    }
    return newNode;
}
trieNode* root;
void insertTrie(string& word){
    trieNode* temp=root;
    for(auto ch:word){
        int idx=ch-'a';
        if(temp->children[idx]==NULL){
            temp->children[idx]= getTrieNode();
        }
        temp=temp->children[idx];
    }
    temp->isEndOfWord=true;
}
string search(string word){
    trieNode* temp=root;
    for(int i=0;i<word.size();i++){
        int idx=word[i]-'a';
        if(!temp->children[idx]){
            return word;
        }
        temp=temp->children[idx];
        if(temp->isEndOfWord) return word.substr(0,i+1);
        
    }
    return word;
}

     string replaceWords(vector<string>& dictionary, string sentence) {
  root= getTrieNode();
       for(int i=0;i<dictionary.size();i++){
        insertTrie(dictionary[i]);
       }
       stringstream ss(sentence);
       string word;
       string result;
    //    while(getline(ss,word,' ')){
    //     result+=search(word)+' ';
    //    }
       while(ss>>word){
           result+=search(word)+' ';
       }
       result.pop_back();//remove the last space
       return result;
    }
};


// dictionary={cat, catt, bat, rat}
// sentence=the cattle
// inset all the words from dictionary to trie, and mark endofword as true
// for cat and catt
// cattle has two prefix, cat and catt, hence we will choose prefix with 
// shortest length ie cat