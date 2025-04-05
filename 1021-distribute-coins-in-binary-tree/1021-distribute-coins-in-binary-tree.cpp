/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
// time complexity=o(n)
// space complexity=o(h)
// int moves=0;
// void movesCount(TreeNode*root, TreeNode*parent){
//      if(!root) return;
//     movesCount(root->left,root);
//     movesCount(root->right,root);

//     if(root->val >=1){
//         int extraCoins= root->val -1;
//         parent->val +=extraCoins;
//         root->val =1;
//         moves+=extraCoins;
//     }
//     else{
//         // int neededCoin =1+abs(root->val);
//               int neededCoin =1;
//         parent->val-=neededCoin;
//         root->val=1;
//         moves+=neededCoin;
//     }
// }
//     int distributeCoins(TreeNode* root) {
//        movesCount(root,root);
//      return moves;  
//     }

int moves=0;
int solve(TreeNode* root){
    if(!root) return 0;//if there is no node then 0 coins will be returned

    int l= solve(root->left);
    int r= solve(root->right);
    moves+=abs(l)+abs(r);
    return (l+r+root->val)-1; // every root should have only 1 coin and remaining it should send to its parent so whatever coins a root receives from left, right and root has subtract -1 and sent to its parent
}

    int distributeCoins(TreeNode* root) {
          solve(root);
          return moves;
    }
};