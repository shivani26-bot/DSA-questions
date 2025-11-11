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
// in the string serialization is necessary to ensure that different tree structures do not accidentally generate the same serialization string.
string dfs(TreeNode* root, unordered_map<string,int>&mp, vector<TreeNode*>&ans){
if(!root) return "N";
string s=to_string( root->val)+","+dfs(root->left,mp,ans)+","+dfs(root->right, mp,ans);
if(mp[s]==1) ans.push_back(root);
mp[s]++;
return s;
}
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // DFS traversal of the tree → visits every node once → O(n) nodes.
//         For each node, you:
// Compute a string serialization of the subtree → concatenating results from left & right.
// Insert/lookup the string in the unordered_map → average O(1).
// Each node’s serialization string length ≈ proportional to the size of its subtree.
// So total string work across all nodes is O(n²) in the worst case — because:
// Each node’s string includes its children’s strings.
// In a skewed tree, serializations overlap in large portions.
// Example:
// For a chain-like tree (every node has one child),
// you build "1,N,N", "2,1,N,N,N", "3,2,1,N,N,N,N", etc.
// → total string concatenation cost = 1 + 2 + 3 + … + n = O(n²).

// Recursion stack: height of tree = O(h) → worst O(n), average O(log n) for balanced tree.
// unordered_map and strings: You store one entry per unique subtree, and each entry can store a string serialization of size proportional to its subtree.
// → in total, can be O(n²) space (same reasoning as above).
// ✅ Average case: O(n) (for map + recursion stack)

  unordered_map<string,int>mp;
        vector<TreeNode*>ans;
        dfs(root,mp,ans);
        return ans;

    }
};

//     1          11
//    /            \
//   1              1
// without comma "11N" → (Root 1, Left 1, Null Right)
// "11N" → (Root 11, Null Left, Right 1)