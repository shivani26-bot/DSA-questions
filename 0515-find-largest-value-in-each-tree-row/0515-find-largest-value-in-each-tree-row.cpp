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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int sz=q.size();
           int maxm=INT_MIN;
            while(sz--){
                TreeNode* node=q.front();
                q.pop();
               
                if(node->val>maxm){
                    maxm=node->val;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
ans.push_back(maxm);

        }
        return ans;
    }
};