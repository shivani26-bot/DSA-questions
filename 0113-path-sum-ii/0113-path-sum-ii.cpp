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
void rootToLeafSumPath(TreeNode* root,int sum,int targetSum,vector<vector<int>>&path,vector<int>&temp){
if(!root) return;
sum+=root->val;
temp.push_back(root->val);

if(!root->left && !root->right && sum==targetSum){
   path.push_back(temp);

}
else{
rootToLeafSumPath(root->left,sum,targetSum,path,temp);
rootToLeafSumPath(root->right,sum,targetSum,path,temp);
}

temp.pop_back();
}




    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        vector<vector<int>>path;
        vector<int>temp;
        rootToLeafSumPath(root,sum,targetSum,path,temp);
        return path;
    }
};