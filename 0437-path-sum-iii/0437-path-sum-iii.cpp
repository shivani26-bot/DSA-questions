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
//naive appraoch time complexity: o(n*n)
//     int count=0;
// void sumPath(TreeNode* root, int targetSum, long sum){
// if(!root) return;
// sum+=root->val;

// if(sum==targetSum){
//     count++;
    
// }
// sumPath(root->left,targetSum,sum);
// sumPath(root->right,targetSum,sum);

// }
//     int pathSum(TreeNode* root, int targetSum) {
//         if(!root) return 0;
    
//         long sum=0;
//     sumPath(root,targetSum,sum);
//     pathSum(root->left,targetSum);
//     pathSum(root->right,targetSum);
//     return count;
//     }
//o(n)
unordered_map<long,long>mp;
 int count=0;
void sumPath(TreeNode* root, int targetSum, long sum){
if(!root) return;
sum+=root->val;

if(sum==targetSum){
    count++;
    
}
if(mp.find(sum-targetSum)!=mp.end()){
    count+=mp[sum-targetSum];
}
mp[sum]++;
sumPath(root->left,targetSum,sum);
sumPath(root->right,targetSum,sum);
mp[sum]--;
}
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
    
        long sum=0;
    sumPath(root,targetSum,sum);
    
    return count;
    }
};