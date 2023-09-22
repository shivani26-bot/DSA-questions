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
vector<int>ans;
void traverse(TreeNode* root){
      if(!root) return;
    traverse(root->left);
  
    ans.push_back(root->val);
    traverse(root->right);
}
    bool isValidBST(TreeNode* root) {
        traverse(root);
        bool   isValid;
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]<ans[i+1]){
               isValid=true;
               continue;
            }
            else{
                isValid=false;
                break;
            }
        }
        return isValid;
      
    }
};