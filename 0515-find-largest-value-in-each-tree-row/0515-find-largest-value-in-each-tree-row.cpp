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
  vector<int>ans;
    vector<int> largestValues(TreeNode* root) {
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
       
      int maxi;
        while(!q.empty()){
            int size=q.size();
         maxi=INT_MIN;
            for(int i=0;i<size;i++){
           
                TreeNode* curr= q.front();
                q.pop();
                
                maxi= max(maxi, curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                            
            }
                            ans.push_back(maxi);
           }
return ans;
    }
};