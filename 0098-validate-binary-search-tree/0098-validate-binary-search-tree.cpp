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
// void traverse(TreeNode* root,long &prev,bool & ans){
//     if(!root) return;
//     traverse(root->left,prev,ans);
//     if(prev<root->val){
//         prev=root->val;
//     }
//     else{
//         ans=false;
//         return;
//     }
//     traverse(root->right,prev,ans);
// }
    // bool isValidBST(TreeNode* root) {
    //     // 1st approach 
    //     // traverse(root);
    //     // bool   isValid;
    //     // for(int i=0;i<ans.size()-1;i++){
    //     //     if(ans[i]<ans[i+1]){
    //     //        isValid=true;
    //     //        continue;
    //     //     }
    //     //     else{
    //     //         isValid=false;
    //     //         break;
    //     //     }
    //     // }
    //     // return isValid;
      
    //   //2nd approach
    //   long prev=LONG_MIN;
    //   bool isValid =true;
    //   traverse(root,prev,isValid);
    //   return isValid;
    // }

    // bool isValidBST(TreeNode* root) {
    //     // 1st approach 
    //     traverse(root);
 
    //     for(int i=0;i<ans.size()-1;i++){
    //         if(ans[i]>=ans[i+1]){
    //            return false;
    //         }
          
    //     }
    //     return true;
      
   
    // }


    // 2nd approach 
    typedef long long ll;
    bool isBst(TreeNode* root, ll min, ll max){
        // if we reach the end node then return true; 
        if(!root) return true;
        // for every node check whether it lies in min max range or not 
        if(root->val<=min || root->val>=max) return false;

// when we move to the left the current node should be max value because all the nodes in the left side must be smaller than it and when we move to the right the current node should be min value because all the nodes in the right side must be larger than it 
        return isBst(root->left, min, root->val) && isBst(root->right, root->val, max);
    }

     bool isValidBST(TreeNode* root) {
// we can maintain a min , max range for every node and when we traverse to left or right, we can
        // check for every node whether it lies within the range or not, if both the sides return true, then return true to parent node 
      
   return isBst(root, LLONG_MIN, LLONG_MAX);
    }
};