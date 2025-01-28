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
void dfs(TreeNode* root, TreeNode*& prev, int& result){
if(!root) return;
    dfs(root->left,prev,result);
     if(prev!=NULL)
    result=min(result, abs(root->val-prev->val));
    prev=root;
    dfs(root->right, prev, result);
   
}
    int minDiffInBST(TreeNode* root) {
        int result=INT_MAX;
        TreeNode* prev=NULL;
        dfs(root,prev,result);
        return result;
    }
};