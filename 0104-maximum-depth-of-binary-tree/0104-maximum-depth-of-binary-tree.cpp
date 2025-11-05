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
    int maxDepth(TreeNode* root) {
        // if(!root) return 0;
        // int level=0;
        // queue<TreeNode*>q;
        // q.push(root);
        // while(!q.empty()){
        //     int size=q.size();
        //     while(size--){
        //         TreeNode* node= q.front();
        //         q.pop();
        //         if(node->left) q.push(node->left);
        //         if(node->right) q.push(node->right);
        //     }
        //     level++;
        // }
        // return level;
        // each node triggers only one recursive call, each node is visited once and per node only max operation is performed ie o(1) hence for n nodes o(n) time complexity
        // space : depends on recursion depth, worst case (balanced tree)-> o(logn)
        // skewed tree->o(n)
        if(!root) return 0;
        int lst=maxDepth(root->left);
        int rst=maxDepth(root->right);
        return 1+max(lst,rst);
    }
};