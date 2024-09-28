// struct Node{
//     Node* links[10];  //0 1 2 3 4 5 6 7 8 9 
//     bool flag=false;
//      void put(char ch, Node* new_node){
//           links[ch-'0']=new_node;
//      }
//      Node* get(char ch){
//         return links[ch-'0'];
//      }
//      bool containsKey(char ch){
//         return links[ch-'0']!=NULL;
//      }
//      void setEnd(){
//         flag=true;

//      }
//      bool isEnd(){
//         return flag;
//      }
// };

// class Solution {
//     private: Node* root;
// public:
// Solution(){
//     root=new Node();
// }
// void insert(string num){
//     Node * node=root;
//     for(auto ch: num){
//         if(!node->containsKey(ch)){
//             node->put(ch,new Node());
//         }
//         node=node->get(ch);
//     }
//     node->setEnd();
// }
// void lcp(string num, int &maxLength){
//     Node* node=root;
//     int len=0;
//     for(auto ch: num){
//         if(!node->containsKey(ch)){
//             return;
//         }
//         len+=1;
//         maxLength=max(maxLength,len);
//         node=node->get(ch);
//     }
// }
//     int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {


// // trie 
// for(auto num: arr1){
//  insert(to_string(num));
// }
// int maxLength=0;
// for(auto num: arr2){
//     lcp(to_string(num),maxLength);
// }
// return maxLength;
//     }
// };

// class Solution {
// public:
//     int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
       
//       unordered_set<string>prefixSet;
//       for(int i=0;i<arr1.size();i++){
//         string num= to_string(arr1[i]);
//         string prefix="";
//         for(auto it: num){
//           prefix+=it;
//           prefixSet.insert(prefix);
//         }
//       }
// int max_length= 0;
//         for(int i=0;i<arr2.size();i++){
//         string num= to_string(arr2[i]);
//         string prefix="";
//         for(auto it: num){
//           prefix+=it;
//           if(prefixSet.find(prefix)!=prefixSet.end()){
//             max_length= max(max_length, static_cast<int>(prefix.size()));
//           }
       
//         }
//       }
//       return max_length;

//  unordered_set<int>prefixSet;
//       for(int i=0;i<arr1.size();i++){
//        while(!prefixSet.count(arr1[i]) && arr1[i]>0){
//         prefixSet.insert(arr1[i]);
//         arr1[i]/=10;
//        }
//       }
// int max_length= 0;
//         for(int i=0;i<arr2.size();i++){
//          while(!prefixSet.count(arr2[i]) && arr2[i]>0){
//         arr2[i]/=10;
//        }
//        if(arr2[i]>0){
//         max_length= max(max_length, static_cast<int>(log10(arr2[i])+1));
//        }
//         }
      
//       return max_length; 
//     }
// };


struct trieNode{
    trieNode* children[10];
};
class Solution {
public:

trieNode* getTrieNode(){
    trieNode* newNode= new trieNode();
    for(int i=0;i<10;i++){
        newNode->children[i]=NULL;
    }
    return newNode;
}
void insert(int num, trieNode* root){
    trieNode* temp=root;
    string numStr= to_string(num);
    for(auto ch: numStr){
        int idx= ch-'0';
        if(!temp->children[idx]){
            temp->children[idx]= getTrieNode();
        }
        temp=temp->children[idx];
    }
}

int search(int num, trieNode* root){
    trieNode* temp=root;
string numStr= to_string(num);
int length=0;
for(char ch: numStr){
    int idx=ch-'0';
    if(temp->children[idx]){
        length++;
        temp=temp->children[idx];
    }
    else break;
}
return length;

}
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        trieNode * root= getTrieNode();
        for(auto num: arr1){
            insert(num, root);
        }
        int result=0;
        for(auto num: arr2){
            result= max(result, search(num,root));
        }
        return result;
    }
};