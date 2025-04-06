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
unordered_map<int,int>mp;
TreeNode* solve(int &preIndex, int postStart, int postEnd, vector<int>& preorder, vector<int>& postorder){
if(postStart>postEnd) return NULL; 
    TreeNode* root= new TreeNode(preorder[preIndex]);
preIndex++;
if(postStart==postEnd) return root; //if there is only one node, 
int postIndex=mp[preorder[preIndex]];
    root->left= solve(preIndex,postStart, postIndex,preorder,postorder);
    root->right=solve(preIndex, postIndex+1,postEnd-1,preorder,postorder);
    return root;
}
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i=0;i<postorder.size();i++){
            mp[postorder[i]]=i;
        }
        int preIndex=0;
       return solve(preIndex, 0,postorder.size()-1,preorder,postorder);

    }
};