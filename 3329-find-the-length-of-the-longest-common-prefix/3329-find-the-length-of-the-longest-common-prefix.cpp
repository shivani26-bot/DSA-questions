class Solution {
public:
    // int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    //     // using set:
    //     // find all the prefixes of arr1 and keep it in set
    //    //123
    //    //st: 123,12,1
    //    //12345
    //    //12345, 1234,123(already present)
    //     unordered_set<int>st;
    //     for(int i=0;i<arr1.size();i++){
    //            int val=arr1[i];
    //            //prefix should not be present
    //            while(!st.count(val) && val>0){
    //             st.insert(val);
    //       val=val/10; //ex: 1000, insert 1000,100,10
    //            }
    //     }
    //     int result=0;//longest common prefix
    //     // go through all the elements in arr2, find out all the prefix of a element, until we don't get the 
    //     // prefix in the set keep on finding the prefix of the element

    //     for(auto num:arr2){
    //         while(!st.count(num) && num>0){
    //             num=num/10;
    //         }
    //         //if we find the element in the set 
    //         if(num>0){
    //             result=max(result,static_cast<int>(log10(num)+1));
    //         }
    //     }
    //     return result;
    // }


   // using trie
struct trieNode{
    trieNode* children[10];
};
trieNode* getTrieNode(){
    trieNode* root= new trieNode();
    for(int i=0;i<10;i++){
        root->children[i]=NULL;
    }
    return root;
}
void insert(trieNode* pCrawl,string num){

    for(int i=0;i<num.length();i++){
        int idx=num[i]-'0';
        if(pCrawl->children[idx]==NULL){
            pCrawl->children[idx]=getTrieNode();
        }
       
            pCrawl=pCrawl->children[idx];
        
    }
}

int search(trieNode* pCrawl,string num){
int length=0;
    for(int i=0;i<num.length();i++){
        int idx= num[i]-'0';
        if(pCrawl->children[idx]){
   
              length++;
            pCrawl=pCrawl->children[idx];
        }
        else{
                   break;
        }
    }
return length;
}
// convert integer to string in order to traverse through the trie
// 10=>"10"
        int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
trieNode* root= getTrieNode();
//insert all the numbers in arr1 to trie, search common prefix for all the numbers from arr2 in trie

for(int i=0;i<arr1.size();i++){
    string num=to_string(arr1[i]);
 insert(root,num);
}
int result=0;
for(int i=0;i<arr2.size();i++){
    string num=to_string(arr2[i]);
    result=max(result,search(root,num));
}
return result;
    }
};