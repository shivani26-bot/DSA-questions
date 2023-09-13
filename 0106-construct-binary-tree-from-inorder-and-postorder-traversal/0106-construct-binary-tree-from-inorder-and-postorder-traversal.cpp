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
 TreeNode* build(int i1,int j1,int i2,int j2,vector<int>& postorder, vector<int>& inorder,map<int,int>&mp){
        if(i1>j1) return NULL;
        TreeNode* root= new TreeNode(postorder[j1],NULL,NULL);
        // int i;
        // for(i=i2;i<=j2;i++){
        //     if(inorder[i]== postorder[j1]) break;
        // }
       
        int i=mp[postorder[j1]];
        //  root->left= build(i1+1,i1+i-i2,i2,i-1,postorder,inorder);
        // root->right= build(i1+i-i2+1,j1,i+1,j2,postorder,inorder);
        root->left= build(i1,i1+i-i2-1,i2,i-1,postorder,inorder,mp);
        root->right= build(i1+i-i2,j1-1,i+1,j2,postorder,inorder,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
    //     int i1 = 0, i2 = 0;
    // int j1 = n - 1, j2 = n - 1;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[inorder[i]]=i;
    }
        // TreeNode* root= build(i1,j1,i2,j2,postorder,inorder);
         TreeNode* root= build(0,n-1,0,n-1,postorder,inorder,mp);
        return root;
    }
};