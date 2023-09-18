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
// find all the paths from root to leaf, in every path find minimum and maximum element 
vector<vector<int>> AllPathFromRootToLeaf;
void  findAllRootToLeafPath(TreeNode* root,vector<int>&temp){
if(!root) return;
if(!root->left && !root->right){
    temp.push_back(root->val);
    AllPathFromRootToLeaf.push_back(temp);
    temp.pop_back();
}

temp.push_back(root->val);
      findAllRootToLeafPath(root->left,temp);
       findAllRootToLeafPath(root->right,temp);
       temp.pop_back();
  }
    int maxAncestorDiff(TreeNode* root) {
        int maxAbsoluteDifference=INT_MIN;
        vector<int>temp;
        findAllRootToLeafPath(root,temp);
        for(auto &i:  AllPathFromRootToLeaf){
           
                int minelement= *min_element(i.begin(),i.end());
                int maxelement= *max_element(i.begin(),i.end());
                  maxAbsoluteDifference= max(maxAbsoluteDifference, abs(maxelement-minelement));
            
          
        }
        return maxAbsoluteDifference;
    }
};