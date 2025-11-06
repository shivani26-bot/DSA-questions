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
// to make a height balanced tree, always split the array into half, the mid element will be root, similarly repeat for left and right subarray
// time: o(n)
// each element in array is visited only once to create a node 
// splitting array take o(1)
// space: no extra space used , o(recursion depth)
// balanced bst o(logn)
TreeNode* makeBST(int s, int e, vector<int>&nums){
    if(s>e) return NULL;
    int mid=(s+e)/2;

    TreeNode* root= new TreeNode(nums[mid]);
    root->left= makeBST(s,mid-1, nums);
    root->right= makeBST(mid+1, e, nums);
    return root;
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       return makeBST(0,nums.size()-1,nums);
    }
};