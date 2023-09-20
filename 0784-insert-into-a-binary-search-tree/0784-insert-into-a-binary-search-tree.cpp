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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            return new TreeNode(val,NULL,NULL);
        }
    TreeNode* temp=root;
    TreeNode* prev=NULL;
    while(temp){
        prev=temp;
        if(temp->val <val){
            temp=temp->right;
        }
        else {
            temp=temp->left;
        }
    }
    if(val > prev->val){
        prev->right= new TreeNode(val, NULL, NULL);
    }
    else{
        prev->left= new TreeNode(val,NULL,NULL);
    }
    return root;
    }
};