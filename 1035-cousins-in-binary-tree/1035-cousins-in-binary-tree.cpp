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
void solve(TreeNode* root, TreeNode* prev, int level,int x,int &xLevel, TreeNode*& parent){
if(!root) return;

if(root->val==x){
    parent=prev;
    xLevel=level;
    return;
}
    solve(root->left,root,level+1,x,xLevel,parent);
    solve(root->right,root,level+1,x,xLevel,parent);
}
    bool isCousins(TreeNode* root, int x, int y) {
    //    dfs approach 
    //  find parent for each x and y and also find level for each of them 
    int aLevel=0;
    int bLevel=0;
    TreeNode* aParent=NULL;
    TreeNode* bParent=NULL;
    solve(root,NULL,0,x,aLevel,aParent);
    solve(root,NULL,0,y,bLevel,bParent);
    return (aLevel==bLevel && aParent!=bParent );
    }
};