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
void solve(TreeNode* root, vector<int>&freq, int& countPaths){
if(!root) return;
    freq[root->val]++;
if(!root->left && !root->right){
    //when we are at leaf node, just iterate through the freq array, and find out how many elements has occured odd times, 
    // if only one or less element has occured odd times it means its a palindromic path 
    int countOddOccurence=0;
    for(int i=0;i<10;i++){
        if(freq[i]%2==1) countOddOccurence++;
    }
    if(countOddOccurence<=1) countPaths++;
}
    solve(root->left,freq,countPaths);
    solve(root->right,freq,countPaths);
    freq[root->val]--;

}
    int pseudoPalindromicPaths (TreeNode* root) {
        // maintain a frequency array, as only 1 to 9 elements are present in the tree, 
        vector<int>freq(10,0);
        // traverse through each path, for each node value in the path increase the frequency,of that element, each index in the frequency array represents the possible node values in the tree 
        int countPaths=0;
 solve(root,freq,countPaths);
    return countPaths;
    }
};