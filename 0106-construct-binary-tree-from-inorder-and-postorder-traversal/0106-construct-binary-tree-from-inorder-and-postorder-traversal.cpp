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
// post order: left right root
// inorder: left root right
// last element of the postorder arr[n-1] will be the main root
// inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// to find right and left subtree of root =3, find index of 3 in inorder
// all the elements left to the 3 is left subtree and all the elements right to the 3 is right subtree
// index of 3 in inorder array= 1
// 0->left subtree
// 2-4->right subtree
TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart,int postEnd)
{
    if(inStart>inEnd) return NULL;
    TreeNode* root=new TreeNode(postorder[postEnd]);
    int i=inStart;
    for(;i<=inEnd;i++){
if(inorder[i]==root->val) break; 
    }
    int leftSize=i-inStart;
    int rightSize=inEnd-i;
    root->left=solve(inorder,postorder, inStart,i-1,postStart,postStart+leftSize-1);
root->right= solve(inorder,postorder, i+1,inEnd,postEnd-rightSize,postEnd-1);
return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int inStart=0,inEnd=n-1;
        int postStart=0,postEnd=n-1;
        return solve(inorder, postorder,inStart, inEnd, postStart, postEnd);

    }
};