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
//  TreeNode*& prev: A reference to a pointer storing the previously visited node during the traversal.
// It is passed by reference (&) so that updates to prev persist across recursive calls.
// int& result: A reference to store the minimum difference between node values. Passing by reference ensures that all recursive calls update the same result variable.
// TreeNode* prev = NULL;
// prev is initialized to NULL to indicate that no previous node has been visited yet.
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