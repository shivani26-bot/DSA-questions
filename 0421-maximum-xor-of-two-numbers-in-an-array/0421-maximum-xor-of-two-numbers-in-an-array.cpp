
class Solution {
public:

// xor property:
// 1^1=0
// 1^0=1
// 0^0=0
// 0^1=1

// 3->    0 1 1
// x->    1 0 0
// xor->  1 1 1
// // in order to get maximum xor, place x bits such that it's opposite of current bit of given number 3

// if x=3, then out of 5,7,2 which number will be xored with 3 to get the maximum xor
// x^5=6 , x^7=4, x^2=1
// 5->101
// 7->111
// 2->010
//    2 1 0
// 3->0 1 1
//  for every bit in num=3 try to find the number out of 5,7,2 whose same bit is opposite to that of current bit of 3 in order to get max result,  
// for 2nd bit of 3 we need 1, only number 5,7 has 1 in it's 2nd  bit
// for 1st bit of 3 we need 0, only number 5 , has 0 in it's 1st bit
// for  0th bit of 3 we need 0, but we have 1 in the 0th bit of 5, take it as it is
// 0 <= nums[i] <= 2^31 - 1 -> 32 bit integers

//  in order to find the bits of num=3
//  i=31;i>=0;i--
// ith_bit= (num>>i) &1;


// bit trie
// num=3 ->0 1 1
// num=4-> 1 0 0 
// num=5-> 1 0 1
// num=7-> 1 1 1
// we can store these numbers in trie in form of bits
//         root
// left (0)   right (1)
//         root
//     0            1
//       1        0
//         1    0    1

// 3,5,2,7=> insert all the numbers in the trie
// 3-> 0 1 1
// 5-> 1 0 1
// xor->6

// find the number which will give max xor when xored with 3
// similary find the number which will give max xor when xored with 5,2,7
// pcrawl is the pointer traversing through the trie
// start from left most bit

//            root
//         0             1 pcrawl
//           1      0 pcrawl     1
//         0   1      1 pcrawl       1

// 5->1 0 1
// 2->0 1 0
// xor-> 7
//                      root
//         0 pcrawl                  1 
//             1 pcrawl           0      1
//         0 pcrawl     1      1            1

struct trieNode{
    trieNode* left;
    trieNode* right;
};
//insert the number into the trie, start from the root
void insert(trieNode* node, int num){
    // trieNode* node=root;
    //find the bit of the number and insert into the node
    for(int i=31;i>=0;i--){
        int bit=(num>>i) & 1;
        if(bit==0){
            //go to left
            if(node->left==NULL){
             node->left= new trieNode();

            }
            node=node->left;
        }
        else{
            // go to right
             if(node->right==NULL){
                node->right=new trieNode();

             }
             node=node->right;
        }
    }
}
int findMaxXor(int num, trieNode* node){
    // trieNode* node= root;
    int maxXor=0;
    for(int i=31;i>=0;i--){
        int bit=(num>>i)&1;
        if(bit==0){
            if(node->right!=NULL){
                 maxXor+=pow(2,i);
                node=node->right;   
            }
            else node=node->left;
        }
        else{
            if(node->left!=NULL) {
                maxXor+=pow(2,i);
                 node=node->left;  
            }
            else node=node->right;
       
        }
    }
    return maxXor;
}
      int findMaximumXOR(vector<int>& nums) {
        trieNode* root= new trieNode();
        // o(n*32)
        for(int i=0;i<nums.size();i++){
            insert(root, nums[i]);
        }
        // iterate in nums array 
        int maxResult=0;
        // o(n*32)
        for(int i=0;i<nums.size();i++){
          int temp=findMaxXor(nums[i],root);
          maxResult=max(maxResult,temp);
        }

        return maxResult;
        // total time: O(32N + 32N) = O(64N) = O(N)

    }

};