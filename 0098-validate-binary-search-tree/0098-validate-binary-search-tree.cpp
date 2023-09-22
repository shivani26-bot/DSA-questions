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
// vector<int>ans;
// void traverse(TreeNode* root){
//       if(!root) return;
//     traverse(root->left);
  
//     ans.push_back(root->val);
//     traverse(root->right);
// }
void traverse(TreeNode* root,long &prev,bool & ans){
    if(!root) return;
    traverse(root->left,prev,ans);
    if(prev<root->val){
        prev=root->val;
    }
    else{
        ans=false;
        return;
    }
    traverse(root->right,prev,ans);
}
    bool isValidBST(TreeNode* root) {
        // 1st approach 
        // traverse(root);
        // bool   isValid;
        // for(int i=0;i<ans.size()-1;i++){
        //     if(ans[i]<ans[i+1]){
        //        isValid=true;
        //        continue;
        //     }
        //     else{
        //         isValid=false;
        //         break;
        //     }
        // }
        // return isValid;
      
      //2nd approach
      long prev=LONG_MIN;
      bool isValid =true;
      traverse(root,prev,isValid);
      return isValid;
    }
};