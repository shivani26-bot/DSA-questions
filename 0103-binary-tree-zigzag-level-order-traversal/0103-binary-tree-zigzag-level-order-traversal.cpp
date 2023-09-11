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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
          if (!root) return {};
          queue<TreeNode*> q;
            q.push(root);
                 vector<vector<int>>finalResult;
                 int level=0;
            while(!q.empty()){
                int size=q.size();
           vector<int>result(size);
          
                for(int i=0;i<size;i++){
                         TreeNode* curr= q.front();
                         q.pop();
                       int index = (level % 2 == 0) ? i : (size - 1 - i);

            // Store the value in the appropriate position.
            result[index] = curr->val;

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
                       
                }
                 level++;
                if (!result.empty()) {
                finalResult.push_back(result);
                }
                 
            }

         return finalResult;
    }
};