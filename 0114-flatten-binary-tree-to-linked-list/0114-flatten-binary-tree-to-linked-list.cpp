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


    void flatten(TreeNode* root) {
         if (!root) {
        return;
    }
      stack<TreeNode*>st;
      st.push(root);
      while(!st.empty()){
          TreeNode* curr=st.top();
          st.pop();
          if(curr->right) st.push(curr->right);
          if(curr->left) st.push(curr->left);
          if(!st.empty())
          curr->right= st.top();
          curr->left=NULL;
      }
    }
};

// figure out the last element on the lst in preorder and connect it to the right subtree
// this question has other two approaches 
// arrange the rst in right skewed manner then lst and finary attatch the root to the lst and rst
// right left root - reverse postorder 
