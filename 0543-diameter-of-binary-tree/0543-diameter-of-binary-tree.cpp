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
// class Solution {
// public:
// // pair<int,int>diameterPair(TreeNode* root){
// //     if(!root) return {0,0};
// //     pair<int,int>lst = diameterPair(root->left);
// //     pair<int,int>rst= diameterPair(root->right);
// //     int height=1+max(lst.first,rst.first);
// //     int diameter= max({lst.first+rst.first,lst.second,rst.second});
// //     return {height,diameter};
// // }

// //     int diameterOfBinaryTree(TreeNode* root) {
// //              return diameterPair(root).second;
// //     }
// int getheight(TreeNode* root) {
//            if(!root) return 0;

       
//            return 1+ max(getheight(root->left),getheight(root->right));    


//   }
//     int diameterOfBinaryTree(TreeNode* root) {
//     //     if(!root) return 0;
//     //      int leftHeight = getheight(root->left);
//     // int rightHeight = getheight(root->right);
    
//     // int leftDiameter = diameterOfBinaryTree(root->left);
//     // int rightDiameter = diameterOfBinaryTree(root->right);
    
//     // return max({leftDiameter, rightDiameter, leftHeight + rightHeight});
//      if(!root) return 0;
//     return max({getheight(root->left)+getheight(root->right), diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)});

//     }
// };
class Solution {
public:


// int findMaxDepth(TreeNode* root){

//  if(!root) return 0;

//         int lst= findMaxDepth(root->left);
//         int rst= findMaxDepth(root->right);
//         return 1+max(lst,rst);
    

// }
//     int diameterOfBinaryTree(TreeNode* root) {
//         if(!root) return 0;

//         int leftDepth= findMaxDepth(root->left);
//         int rightDepth= findMaxDepth(root->right);
//         return max({leftDepth+rightDepth,diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)});
//     }

// ✅ Time Complexity:
// O(n) — Each node is visited exactly once, and we do constant work (max and addition) per node.
// ✅ Space Complexity:
// O(h) — recursion stack height (worst case = height of the tree).
// If the tree is balanced → O(log n)
// If the tree is skewed → O(n)
int solve(TreeNode* root, int& result){
    if(!root) return 0;
    int lst= solve(root->left, result);
    int rst= solve(root->right, result);
    result= max(result, lst+rst);
    return 1+max(lst,rst);
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
int result= INT_MIN;
solve(root,result);
return result;
    }
};