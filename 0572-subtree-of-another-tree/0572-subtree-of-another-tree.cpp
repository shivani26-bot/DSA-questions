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
bool check(TreeNode* root, TreeNode* subRoot){
     if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        return (root->val== subRoot->val && check(root->left,subRoot->left) && check(root->right,subRoot->right));
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
       if(check(root,subRoot)) return true;

bool lst=isSubtree(root->left,subRoot) ;
 bool rst= isSubtree(root->right,subRoot);
 return lst || rst;
       

    }
};