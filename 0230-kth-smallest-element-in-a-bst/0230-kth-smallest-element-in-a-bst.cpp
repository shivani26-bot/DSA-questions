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


//  class Solution {
// public:
// void traverse(TreeNode* root,int &count,int &ans, int k){
//     // if(!root || count>=k) return ;
//     // traverse(root->left,count,ans,k);
//     // count++;
//     // if(count==k){
//     //     ans=root->val;
//     //     return;
//     // }
//     // traverse(root->right,count,ans,k);

//  if(!root) return ;
//     traverse(root->left,count,ans,k);
//   // first compare count with k and then increment the count
//     if(count++==k){
 
//         ans=root->val;
//         return;
//     }
//     traverse(root->right,count,ans,k);

// }
//     int kthSmallest(TreeNode* root, int k) {
//     //     int count=0;
//     //     int ans=-1;
//     //    traverse(root,count,ans,k) ;
//     //    return ans;
//     int count=1;
//         int ans=-1;
//        traverse(root,count,ans,k) ;
//        return ans;
//     }
// };
class Solution {
public:
vector<int>ans;
void inorder(TreeNode* root){

if(!root) return;
    inorder(root->left);
    ans.push_back(root->val);
    inorder(root->right);
}
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return ans[k-1];
    }
};