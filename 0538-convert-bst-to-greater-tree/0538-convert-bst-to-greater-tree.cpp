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
int sum=0;
void convertBst(TreeNode* root){
    if(!root) return;

    convertBst(root->right);
    sum+=root->val;
    root->val=sum;
    convertBst(root->left);
    //  if(!temp) return;

    // convertBst(temp->right,temp);
    // sum+=temp->val;
    // temp->val=sum;
    // convertBst(temp->left,temp);
    // return;
}
    TreeNode* convertBST(TreeNode* root) {
        // TreeNode* temp=root;
        convertBst(root);
        return root;
    }
};