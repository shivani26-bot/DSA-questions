class Solution {
public:
//  wordsContainer = ["abcd","bcd","xbcd"], wordsQuery = ["cd","bcd","xyz"]
// for each element:  for ex: bcd, possible suffix: d,cd, bcd
// in this way try longest suffix which is common in wordsContainer array
// check from the last index of each word in wordsContainer that whether the suffix is present or not

// to find the common suffix in wordsContainer, store each word of wordsContainer in trie in reverse order
// if word is abcd, store it as dcba in trie
// we can also store index parallely while storing each letter 
// while we store abcd as dcba in trie store index=0,
// when we insert bcd as dcb in trie check whether index=0 stored for that leter has length > or < than current index=1
// element at index=1 is smaller than element at index=0 hence update the index

// now search each query in trie

// for search query xyz, search from the end zxy, we don't find z in the root, it means, "" suffix is matched 
// "" empty string is present in each word in wordsContainer hence send the index of word with smallest length as the answer 
// store the index in root also,in case if we don't get any answer for ex: in case of "" empty string , then return the index present in root only, as it will store the index of the word with smallest length;
   struct trieNode{
    trieNode* children[26];
    int idx;

    // add destructor to remove memory limit exceeded
    ~trieNode(){
        for(int i=0;i<26;i++){
            delete children[i];
        }
    }
   };
   trieNode* getNode(int i){
    trieNode* temp= new trieNode();
    temp->idx=i;
    for(int i=0;i<26;i++){
        temp->children[i]=NULL;
    }
    return temp;
   }
   void insertTrie(trieNode* pCrawl, int i,vector<string>& wordsContainer){
            string word= wordsContainer[i];
            int n=word.length();
            for(int j=n-1;j>=0;j--){
                char ch=word[j];
                int ch_idx=ch-'a';
                if(pCrawl->children[ch_idx]==NULL){
                     pCrawl->children[ch_idx]=getNode(i);

                }
                //move to next element
                pCrawl=pCrawl->children[ch_idx];
                // if not null
                //if length of the word at index = root->idx is greater than current word length then update theroot->idx 
                if(wordsContainer[pCrawl->idx].length()>n){
                    pCrawl->idx=i;
                }
            }
   }
   int searchTrie(trieNode* pCrawl, string &word){
       int n=word.length();
       int result_idx=pCrawl->idx;
       for(int i=n-1;i>=0;i--){
        int ch_idx=word[i]-'a';
        pCrawl=pCrawl->children[ch_idx];
        if(!pCrawl){
            return result_idx;
        }
        result_idx=pCrawl->idx;//update the result
       }
       return result_idx;
   }
   vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int m=wordsContainer.size();
        int n=wordsQuery.size();
        vector<int>result(n);
// store the index of shortest string in root, so that if we find "" empty string then return the answer stored in the root
trieNode* root= getNode(0);
for(int i=0;i<m;i++){
int idx=root->idx;
    if(wordsContainer[idx].size()>wordsContainer[i].size()){
        root->idx=i;
    }
    insertTrie(root, i, wordsContainer);
}
for(int i=0;i<n;i++){
    result[i]= searchTrie(root, wordsQuery[i]);
}
delete root;
return result;

    }
};