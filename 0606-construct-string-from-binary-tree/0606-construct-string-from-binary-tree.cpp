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
    string tree2str(TreeNode* root) {
        
        string ans = to_string(root->val);
		if (root->left) //left side check
			ans += "(" + tree2str(root->left) + ")";
		if (root->right) { //right side check
			if (!root->left) ans += "()"; //left side not present, but right side present
			ans += "(" + tree2str(root->right) + ")"; 
		}
		return ans;
    }
};
//  class Solution {
// public:
  
//     string tree2str(TreeNode* root) {
//         if(!root) return "";
//     string ans=to_string(root->val);
//     if(root->left || root->right){
//         ans+= "("+ tree2str(root->left)+")";
//     }
//     if(root->right) ans+= "("+tree2str(root->right)+")";
//     return ans;
//     }
// };
// class Solution {
// public:
  
//     string tree2str(TreeNode* root) {
//      if (!root) {
//         return "";
//     }

//     string result = to_string(root->val);

//     if (root->left || root->right) {
//         result += "(" + tree2str(root->left) + ")";
//     }

//     if (root->right) {
//         result += "(" + tree2str(root->right) + ")";
//     }

//     return result;
//     }
// };
// class Solution {
// public:
// void dfs(TreeNode* root, string &ans){
//     ans+=to_string(root->val);
//     if(!root) return;
// if(!root->left && !root->right) return;

// if(root->left){
//     ans+='(';
//     dfs(root->left,ans);
//     ans+=')';
// }
// if(!root->left && root->right) {
//     ans+='(';
//     ans+=')';
// }
// if(root->right){
//      ans+='(';
//     dfs(root->right,ans);
//     ans+=')';
// }

// }
//     string tree2str(TreeNode* root) {
//         string ans;
//         dfs(root,ans);
//         return ans;
//     }
// };