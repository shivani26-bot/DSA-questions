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

struct SubTreeDetails {
    bool isBST;
    long minval;
    long maxval;
    long sum;

    SubTreeDetails(bool isBST, long minval, long maxval, long sum) {
        this->isBST = isBST;
        this->minval = minval;
        this->maxval = maxval;
        this->sum = sum;
    }
};

class Solution {
public:
 SubTreeDetails* getLargestBST(TreeNode* root, int& maxSum) {
        if (!root) return new SubTreeDetails(true, LONG_MAX, LONG_MIN, 0);
        SubTreeDetails* lst = getLargestBST(root->left, maxSum);
        SubTreeDetails* rst = getLargestBST(root->right, maxSum);
        bool isBST = lst->isBST && rst->isBST && root->val > lst->maxval && root->val < rst->minval;
        long sum = root->val + lst->sum + rst->sum;
        long minval = min({(long)root->val, lst->minval, rst->minval});
        long maxval = max({(long)root->val, lst->maxval, rst->maxval});
        if (isBST == true) {
            maxSum = max((long)maxSum, sum);
        }
        return new SubTreeDetails(isBST, minval, maxval, sum);
    }
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        getLargestBST(root, maxSum);
        return maxSum;
    }
};