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
    // TreeNode* insertIntoBST(TreeNode* root, int val) {
    //     if(!root) return new TreeNode(val);
    //     TreeNode* parent=NULL;
    //     TreeNode* temp=root;
        
    //     while(temp){
    //            parent=temp;
    //         if(temp->val < val){
             
    //             temp=temp->right;
    //         }
    //         else if(temp->val>=val){
    //           temp=temp->left;
    //         }

    //     }
    //     if(parent->val < val) parent->right= new TreeNode(val);
    //     else parent->left=new TreeNode(val);

    //     return root;
    // }

void dfs(TreeNode* root, TreeNode* parent, int val){
if(!root){
    TreeNode* newNode= new TreeNode(val);
    if(parent->val>val) parent->left= newNode;
    else if(parent->val<val) parent->right= newNode;
    return;
}

    if(root->val>val){
        dfs(root->left, root, val);
    }
    if(root->val<val){
        dfs(root->right, root, val);
    }

}
      TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(!root) { 
        TreeNode* newNode= new TreeNode(val);
        return newNode;
        }
       dfs(root,NULL,val);
       return root;
    }
};