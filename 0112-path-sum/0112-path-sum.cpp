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
bool pathSum(TreeNode* root, int targetSum,int &sum){
    // if(!root->left && !root->right){
    //     sum+=root->val;
    //     if(sum==targetSum) return true;
    //     else{
    //         sum-=root->val;
    //         return false;
    //     }
    // }
if(!root) {
 return false;
}

    sum+=root->val;
    if(!root->left && !root->right){
       
        if(sum==targetSum) return true;
       
    }
    bool lst= pathSum(root->left, targetSum, sum);
    bool rst= pathSum(root->right, targetSum, sum);

    sum-=root->val;
    return lst||rst;
}
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        int sum=0;
        return pathSum(root, targetSum,sum);
    }
};