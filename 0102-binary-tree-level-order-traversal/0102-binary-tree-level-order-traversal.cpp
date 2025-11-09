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
// time: o(n)
// each node is pushed/popped once in/from queue, constnat work per node 
// space: o(w+n)
// w= in worst case queue holds all the nodes from widest level of tree
// In the worst case (a full binary tree), W ≈ N/2 → O(N).
// In a balanced tree, W ≈ O(N/2) but still O(N) asymptotically.
// for ans array n  space, storing all nodes in tree 
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size= q.size();
            vector<int>temp;
            while(size--){
                TreeNode* node= q.front();
                                temp.push_back(node->val);
                q.pop();

                if(node->left){
                   q.push(node->left);   
                }
                  if(node->right){
                    q.push(node->right);                 
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};