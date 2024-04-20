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
string ans;
void smallestString(TreeNode* root, string s){

if(!root) return;
//    'a' + root->val calculates the ASCII value of the character 'a' and adds the value of
//  root->val to it. This operation converts the integer value stored in root->val to the 
//  corresponding ASCII character code. For example, if root->val is 0, then 'a' + 0 is 'a', and
//   if root->val is 1, then 'a' + 1 is 'b'
// char('a' + root->val) converts the resulting integer value back to a character. This is necessary
//  because path is a string, and we want to concatenate a character to it.
   s=  char('a' + root->val) +s;
    if(!root->left && !root->right){
     if(ans.empty() || ans>s) ans=s;
     return;
    }
    smallestString(root->left,s);
    smallestString(root->right,s);
}
    string smallestFromLeaf(TreeNode* root) {
        smallestString(root,"");
        return ans;
    }
};