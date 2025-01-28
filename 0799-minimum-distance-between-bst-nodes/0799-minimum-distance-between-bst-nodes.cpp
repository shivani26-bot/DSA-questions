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
 //traversing the bst in inorder we will get the sorted order of nodes
class Solution {
public:
// void dfs(TreeNode* root, TreeNode*& prev, int& result){
// if(!root) return;
//     dfs(root->left,prev,result);
//      if(prev!=NULL)
//     result=min(result, abs(root->val-prev->val));
//     prev=root;
//     dfs(root->right, prev, result);
   
// }
//     int minDiffInBST(TreeNode* root) {
//         int result=INT_MAX;
//         TreeNode* prev=NULL;
//         dfs(root,prev,result);
//         return result;
//     }

void dfs(TreeNode* root, vector<int>& arr){
if(!root) return;
    dfs(root->left,arr);
   arr.push_back(root->val);
    dfs(root->right, arr);
   
}
    int minDiffInBST(TreeNode* root) {
        vector<int>arr;
int result=INT_MAX;
        dfs(root,arr);
        for(int i=0;i<arr.size()-1;i++){
            result=min(result, abs(arr[i]-arr[i+1]));
        }
        return result;
    }
};