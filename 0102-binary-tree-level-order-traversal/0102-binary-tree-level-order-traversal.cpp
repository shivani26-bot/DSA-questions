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
    vector<vector<int>> levelOrder(TreeNode* root) {
            queue<TreeNode*> q;
            q.push(root);
                 vector<vector<int>>finalResult;
            while(!q.empty()){
                int size=q.size();
           vector<int>result;
                for(int i=0;i<size;i++){
                         TreeNode* curr= q.front();
                         q.pop();
                          if (curr) {
                         result.push_back(curr->val);
                         if(curr->left) q.push(curr->left);
                         if(curr->right) q.push(curr->right);
                          }
                }
                if (!result.empty()) {
                finalResult.push_back(result);
                }
            }

         return finalResult;
    }
};