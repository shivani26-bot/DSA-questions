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
        if(!root) return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        int level=0; //right to left
        while(!q.empty()){
                int size=q.size();
                    vector<int>temp(size);
              for(int i=0;i<size;i++){
  TreeNode* node= q.front();
            q.pop();
    int index= (level%2==0)?i:(size-i-1);
    
        temp[index]=node->val;
           
    
                  if(node->left) q.push(node->left);
                        if(node->right) q.push(node->right);
      
        }
 if(!temp.empty()){
    ans.push_back(temp);
 }
 level++;
                }
          return ans;

    }
};