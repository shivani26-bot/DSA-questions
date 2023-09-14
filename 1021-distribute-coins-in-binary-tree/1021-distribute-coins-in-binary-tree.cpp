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
int moves=0;
void movesCount(TreeNode*root, TreeNode*parent){
     if(!root) return;
    movesCount(root->left,root);
    movesCount(root->right,root);

    if(root->val >=1){
        int extraCoins= root->val -1;
        parent->val +=extraCoins;
        root->val =1;
        moves+=extraCoins;
    }
    else{
        int neededCoin =1+abs(root->val);
        parent->val-=neededCoin;
        root->val=1;
        moves+=neededCoin;
    }
}
    int distributeCoins(TreeNode* root) {
     movesCount(root,root);
     return moves;
    }
};