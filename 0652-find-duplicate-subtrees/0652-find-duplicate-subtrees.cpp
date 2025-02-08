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
// in the string serialization is necessary to ensure that different tree structures do not accidentally generate the same serialization string.
string dfs(TreeNode* root, unordered_map<string,int>&mp, vector<TreeNode*>&ans){
if(!root) return "N";
string s=to_string( root->val)+","+dfs(root->left,mp,ans)+","+dfs(root->right, mp,ans);
if(mp[s]==1) ans.push_back(root);
mp[s]++;
return s;
}
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
  unordered_map<string,int>mp;
        vector<TreeNode*>ans;
        dfs(root,mp,ans);
        return ans;

    }
};

//     1          11
//    /            \
//   1              1
// without comma "11N" → (Root 1, Left 1, Null Right)
// "11N" → (Root 11, Null Left, Right 1)