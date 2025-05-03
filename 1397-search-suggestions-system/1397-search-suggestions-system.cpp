struct trieNode{
    trieNode* children[26];
//     At each TrieNode, we include a priority queue that stores up to 3 words that share the current character in the trie.
// Our priority queue comparator will keep the larger lexicoographical word on top. The reason we do this is so that we can pop it off whenever our pq exceeds a size of 3.
    priority_queue<string>pq;
  trieNode(){//constructor
    for(int i=0;i<26;i++){
     children[i]=NULL;
    }
}

      void addToPQ(string& word){
        pq.push(word);
        if(pq.size()>3)  pq.pop();
    }

      vector<string> getTopThree(){
        vector<string> temp;
          priority_queue<string> copy = pq;
        while(!copy.empty()){ 
            temp.push_back(copy.top());
            copy.pop();
            }
     reverse(temp.begin(),temp.end());
        return temp;

    }
};

class Trie{
    trieNode* root;
    public:
    Trie(){
        root=new trieNode();
    }

    void insert(string word){
        trieNode* node=root;
      for(auto ch: word){
        int idx=ch-'a';
        if(node->children[idx]==NULL){
            node->children[idx]=new trieNode();
        }
        node=node->children[idx];
        node->addToPQ(word);
      }
    }
  
    void search(string searchWord, vector<vector<string>>&ans){
             trieNode* node=root;
        for(auto ch: searchWord){
            int idx=ch-'a';
if(node && node->children[idx]!=NULL){
    node=node->children[idx];
    ans.push_back(node->getTopThree());
}
else{
    node=NULL;
    ans.push_back({});
}
        }

    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
       int n=products.size();
    //    sort(products.begin(),products.end());
       Trie trie;
       for(int i=0;i<n;i++){
trie.insert(products[i]);
       }
       vector<vector<string>>ans;
   trie.search(searchWord,ans);
   return ans;
    }
};


// struct trieNode{
//     trieNode* children[26];
// vector<string>suggestions;
// };

// class Trie{
//     trieNode* root;
//     public:
//     Trie(){
//         root=new trieNode();
//     }

//     void insert(string word){
//         trieNode* node=root;
//       for(auto ch: word){
//         int idx=ch-'a';
//         if(node->children[idx]==NULL){
//             node->children[idx]=new trieNode();
//         }
//         node=node->children[idx];
//         if(node->suggestions.size()<3)
//         node->suggestions.push_back(word);
//       }
//     }
  
//     void search(string searchWord, vector<vector<string>>&ans){
//              trieNode* node=root;
//         for(auto ch: searchWord){
//             int idx=ch-'a';
// if(node && node->children[idx]!=NULL){
//     node=node->children[idx];
//     ans.push_back(node->suggestions);
// }
// else{
//     node=NULL;
//     ans.push_back({});
// }
//         }

//     }
// };
// class Solution {
// public:
//     vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
//        int n=products.size();
//        sort(products.begin(),products.end());
//        Trie trie;
//        for(int i=0;i<n;i++){
// trie.insert(products[i]);
//        }
//        vector<vector<string>>ans;
//    trie.search(searchWord,ans);
//    return ans;
//     }
// };