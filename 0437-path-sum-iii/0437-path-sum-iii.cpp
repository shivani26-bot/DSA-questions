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
    int count=0;
void sumPath(TreeNode* root, int targetSum, long sum){
if(!root) return;
sum+=root->val;

if(sum==targetSum){
    count++;
    
}
sumPath(root->left,targetSum,sum);
sumPath(root->right,targetSum,sum);

}
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
    
        long sum=0;
    sumPath(root,targetSum,sum);
    pathSum(root->left,targetSum);
    pathSum(root->right,targetSum);
    return count;
    }
};