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
void height(TreeNode* root,int x,int level,int &xlevel,TreeNode* pre, TreeNode* &parent){
    if(!root) return;
     if(root->val==x){
        xlevel=level;
        parent=pre;
        return;
    }
    
    height(root->left,x,level+1,xlevel,root,parent);
    height(root->right,x,level+1,xlevel,root,parent);
   
}
    bool isCousins(TreeNode* root, int a, int b) {
        int alevel=0;
   int blevel=0;
   TreeNode* aparent=NULL;
   TreeNode* bparent=NULL;
   height(root,a,0,alevel,NULL,aparent);
   height(root,b,0,blevel,NULL,bparent);
   return (alevel==blevel && aparent!=bparent);
    }
};