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
// long long int ans=0;
// void sumRootToLeaf(TreeNode* root, string num){
//     if(!root) return;
//      if(!root->left && !root->right){
//             num+=to_string(root->val);
//            ans+=(stoi(num));
//            return;
//       }
//     num+=to_string(root->val);
//       sumRootToLeaf(root->left, num);
//       sumRootToLeaf(root->right, num);
// }
//     int sumNumbers(TreeNode* root) {
//         string str;
//         sumRootToLeaf(root,str);
//        return ans;
//     }

// int sumRootToLeaf(TreeNode* root, int sum){
//     if(!root) return 0;
//      if(!root->left && !root->right){
//              sum= sum*10+ root->val;
//            return sum;
//       }
//     sum= sum*10+ root->val;
//     return  sumRootToLeaf(root->left, sum) +  sumRootToLeaf(root->right, sum);
     
// }
//     int sumNumbers(TreeNode* root) {
        
//        return sumRootToLeaf(root,0);
//     }


int solve(TreeNode* root, int num){
if(!root) return 0;
if(!root->right && !root->left){
     num=num*10+root->val;
     return num;
}
    num=num*10+root->val;
    int l=solve(root->left,num);
    int r=solve(root->right,num);
    return l+r;
}

    int sumNumbers(TreeNode* root) {
        
       return solve(root,0);
    }
};