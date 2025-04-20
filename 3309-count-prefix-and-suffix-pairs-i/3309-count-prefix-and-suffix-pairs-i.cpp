struct trieNode{
    trieNode* children[26];
    // bool isEndOfWord;//not really required for this question, but good practice
};

trieNode* getTrieNode(){
    trieNode* node= new trieNode();
    for(int i=0;i<26;i++){
        node->children[i]=NULL;
    }
    // node->isEndOfWord=false;
    return node;
}

class Trie{
    public:
    trieNode* root;
Trie(){
    root=getTrieNode();
}
void insert( string word){
trieNode* pCrawl=root;
    for(auto ch: word){
        int idx=ch-'a';
        if(!pCrawl->children[idx]){
            pCrawl->children[idx]= getTrieNode();

        }
        pCrawl= pCrawl->children[idx];
    }
    // pCrawl->isEndOfWord=true;

}
bool searchPrefix(string prefix){
    trieNode* pCrawl=root;
  for(auto ch: prefix){
    int idx= ch-'a';
    if(!pCrawl->children[idx]) return false;
    pCrawl=pCrawl->children[idx];
  }
  return true;
}
};

class Solution {
public:
    // int countPrefixSuffixPairs(vector<string>& words) {
    //     // int n=words.size();
    //     // int count=0;
    //     // for(int i=0;i<n;i++){
    //     //     for(int j=i+1;j<n;j++){
    //     //     string str1=words[i];
    //     //     string str2=words[j];
    //     //     if(str2.find(str1)==0 && str2.rfind(str1)==str2.length()-str1.length())
    //     //                count+=1;
    //     //     }
    //     // }
    //     // return count;

    //     int n=words.size();
    //     int count=0;
    //     for(int i=0;i<n-1;i++){
    //         int m=words[i].size();
    //         string str1=words[i];
    //         for(int j=i+1;j<n;j++){
                
    //             string str2=words[j];
    //             int k=words[j].size();
    //              if (m <= k) {
    //             string prefix=str2.substr(0,m);
    //             string suffix=str2.substr(k-m,m);
    //             if(prefix==str1 && suffix==str1) count+=1;
    //              }
    //         }
    //     }
    //     return count;


    // }


        int countPrefixSuffixPairs(vector<string>& words) {
// for prefix search we will store each element in trie as it is and search it
// but for suffix search we will store the element in trie in reverse order
// and we will search also the reverse word
// abc, abcxyabc
// in order to search abc as prefix we will store abcxyabc as it is and search abc
// in order to search abc as suffix we will store abcxyabc in reverse order in trie, cbayxcba and search cba as prefix
    int n=words.size();
    int count=0;
// Total = ∑ O(i*l) for i = 0 to n-1
//       = O(l) * ∑ i = O(l * n(n-1)/2) = O(n² * l)
 //o(n)
// l->max length of the word
    for(int i=0;i<n;i++){
      Trie prefixTrie;
      Trie suffixTrie;
    //   o(l)
       prefixTrie.insert(words[i]);
        string reversed= words[i];
        reverse(begin(reversed),end(reversed));
        //o(l)
    suffixTrie.insert(reversed);
//worst case: inner loop runs i times
// i* o(3l)=> o(i*l)


        for(int j=0;j<i;j++){
            if(words[j].length()>words[i].length()) continue;
            string rev=words[j];
                          //reverse-o(l)
           reverse(begin(rev),end(rev));
             //search-o(l)
           if(prefixTrie.searchPrefix(words[j]) && suffixTrie.searchPrefix(rev)){
            count++;
           }
        }
    }

    return count;
    }
};