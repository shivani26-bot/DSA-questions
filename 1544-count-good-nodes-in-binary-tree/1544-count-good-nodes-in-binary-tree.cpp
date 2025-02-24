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
void solve(TreeNode* root, int &count, int maxEle){
    if(!root) return;
    maxEle=max(maxEle,root->val);

    if(root->val>=maxEle) count++;
    solve(root->left,count,maxEle);
    solve(root->right,count,maxEle);
}
    int goodNodes(TreeNode* root) {
       int count=0;
       int maxEle=INT_MIN;
      solve(root,count,maxEle);
      return count;
      
    }
};