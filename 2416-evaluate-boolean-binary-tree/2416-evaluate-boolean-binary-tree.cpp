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
bool check(TreeNode* root){
    if(!root) return false;
    if(!root->left && !root->right){
        if(root->val==1) return true;
        else return false;
    }
    bool lst=check(root->left);
    bool rst=check(root->right);
 
    return (root->val==2) ? (lst && rst) :(lst || rst);
}
    bool evaluateTree(TreeNode* root) {
       if(!root) return false;
       return check(root);
    }
};