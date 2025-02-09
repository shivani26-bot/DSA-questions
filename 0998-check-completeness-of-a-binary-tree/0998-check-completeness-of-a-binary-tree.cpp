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
// bool dfs(TreeNode* root){
//     if(!root) return true;
// if(!root->left && !root->right) return true;
// if(!root->left) return false;

// bool lst=dfs(root->left) ;
// bool rst=dfs(root->right);
// return lst && rst;
// }
bool bfs(TreeNode* root,int totalLevels){
    queue<TreeNode*>q;
    q.push(root);
      bool foundNull=false;
    while(!q.empty()){
      TreeNode* node= q.front();
      q.pop();

      if(!node) {
        foundNull=true;
      }
      else{
        if(foundNull) return false;
        q.push(node->left);
        q.push(node->right);
        cout<<node->left<<" "<<node->right<<endl;
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
    //  if(!root->left && !root->right) return true;
  int totalLevels=  height(root);
  cout<<totalLevels<<endl;
//  if at last level we find null then after that null there should be no elements after it

// if any node has seen null in the past it means it's not a complete binary tree

return bfs(root,totalLevels);
//  return true;

    }
};