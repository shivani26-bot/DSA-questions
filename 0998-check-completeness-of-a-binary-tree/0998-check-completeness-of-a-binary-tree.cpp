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

bool bfs(TreeNode* root){
    queue<TreeNode*>q;
    q.push(root);
      bool foundNull=false;
    while(!q.empty()){
      TreeNode* node= q.front();
      q.pop();

      if(!node) {
        foundNull=true; //if node is null mark it true
      }
      else{ //if node is present then check whether have seen null in past or not if yes then return false other wise push the left and right child 
        if(foundNull) return false;
        q.push(node->left);
        q.push(node->right);// if there is null node it pushes 0, if there is node it pushes the address of the node
        // cout<<node->left<<" "<<node->right;
      }
        
    }
    return true;
}
int height(TreeNode* root)
{
  if(!root) return 0;
  int lst= height(root->left);
  int rst= height(root->right);
  return 1+max(lst,rst);
}
    bool isCompleteTree(TreeNode* root) {

//  if at last level we find null then after that null there should be no elements after it

// if any node has seen null in the past it means it's not a complete binary tree

return bfs(root);


    }
};