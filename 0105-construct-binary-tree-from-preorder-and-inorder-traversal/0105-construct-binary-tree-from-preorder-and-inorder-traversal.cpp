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
 TreeNode *buildTree(vector<int>&pre,int preStart,int preEnd,vector<int>in,int inStart,int inEnd,map<int,int>&mp){
        if(preStart>preEnd || inStart>inEnd)
        return NULL;
      
        TreeNode* root=new TreeNode(pre[preStart]);
          if(preStart==preEnd )
        {
            return root;
        }
        int inRoot=mp[root->val];
        int numsLeft=inRoot-inStart;
        root->left=buildTree(pre,preStart+1,preStart+numsLeft,in,inStart,inRoot-1,mp);
        root->right=buildTree(pre,preStart+numsLeft+1,preEnd,in,inRoot+1,inEnd,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode*root=buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
};