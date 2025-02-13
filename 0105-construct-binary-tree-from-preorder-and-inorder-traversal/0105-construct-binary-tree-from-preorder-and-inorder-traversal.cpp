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
TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int inStart,int inEnd, int preStart, int preEnd){
    if(inStart>inEnd) return NULL;
    TreeNode* root= new TreeNode(preorder[preStart]);
    int i=inStart;
    for(;i<=inEnd;i++){
        if(inorder[i]==root->val) break;
    }
    int leftSize=i-inStart;
    int rightSize= inEnd-i;
    root->left= solve(preorder,inorder, inStart,i-1,preStart+1, preStart+leftSize);
    root->right= solve(preorder,inorder, i+1,inEnd,preEnd-rightSize+1, preEnd);
    return root;

}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int inStart=0,inEnd=n-1;
        int preStart=0, preEnd=n-1;
        return solve(preorder,inorder, inStart, inEnd, preStart, preEnd);
    }
};