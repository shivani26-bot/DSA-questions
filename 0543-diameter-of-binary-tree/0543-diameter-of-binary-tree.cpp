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
// int findMaxDepth(TreeNode* root){

//  if(!root) return 0;

//         int lst= findMaxDepth(root->left);
//         int rst= findMaxDepth(root->right);
//         return 1+max(lst,rst);
    

// }
//     int diameterOfBinaryTree(TreeNode* root) {
//         if(!root) return 0;

//         int leftDepth= findMaxDepth(root->left);
//         int rightDepth= findMaxDepth(root->right);
//         return max({leftDepth+rightDepth,diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)});
//     }


int solve(TreeNode* root, int& result){
    if(!root) return 0;
    int lst= solve(root->left, result);
    int rst= solve(root->right, result);
    result= max(result, lst+rst);
    return 1+max(lst,rst);
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
int result= INT_MIN;
solve(root,result);
return result;
    }
};