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
        if(!root) return 0;
        int lst=maxDepth(root->left);
        int rst=maxDepth(root->right);
        return 1+max(lst,rst);
    }
};