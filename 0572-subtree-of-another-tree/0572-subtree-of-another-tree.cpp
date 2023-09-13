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
// bool areSame(TreeNode* r1, TreeNode* r2){
//  if(!r1 && !r2) return true;
//         if(!r1 || !r2) return false;
//        return r1->val == r2->val && areSame(r1->left,r2->left) && areSame(r1->right,r2->right);

// }
void preorderTraversal(TreeNode* root, vector<int>& array){
          if(!root){
        array.push_back(INT_MIN);
        return;
        }
        array.push_back(root->val);
        preorderTraversal(root->left,array);
        preorderTraversal(root->right,array);
    return;

}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //    if(!root) return false;
        //  if(areSame(root,subRoot)){
        //      return true;
        //  }
      
        // return  isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);

        vector<int>preorderArray1,preorderArray2;
        preorderTraversal(root,preorderArray1);
        preorderTraversal(subRoot,preorderArray2);
        if(preorderArray1.size()<preorderArray2.size()) return false;
        for(int i=0;i<=preorderArray1.size()-preorderArray2.size();i++){
            int c=0;
            for(int j=i;j<i+preorderArray2.size();j++){
                if(preorderArray1[j]==preorderArray2[j-i]) c++;
            }
              if(c==preorderArray2.size()) return true;
        }
      return false;
    }
        
    
};