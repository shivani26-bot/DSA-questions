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
    int findBottomLeftValue(TreeNode* root) {
        int level=0;
        queue<TreeNode*>q;
        q.push(root);
         int leftnode;
        while(!q.empty()){
            int size=q.size();
         leftnode= q.front()->val;
            while(size--){
                TreeNode* node= q.front();
                q.pop();
if(node->left) q.push(node->left);
if(node->right) q.push(node->right);
            }
        }
        return leftnode;
    }
};