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

bool check(TreeNode* p, TreeNode* q){
    if(!p && !q) return true;
    if(!q || !p) return false;

  

 bool left=check(p->left, q->left);
 bool right= check(p->right, q->right);

 return p->val== q->val &&left && right;
}
    bool isSameTree(TreeNode* p, TreeNode* q) {
    

        return check(p,q);
    }
// bool check(TreeNode* p, TreeNode* q){
//       if(!p && !q) return true;
//     if(!q || !p) return false;
//  return ( p->val== q->val && check(p->left, q->left) && check(p->right, q->right));
// }
//     bool isSameTree(TreeNode* p, TreeNode* q) {
    

//         return check(p,q);
//     }


    // bool isSameTree(TreeNode* p, TreeNode* q) {
    //       if(!p && !q) return true;
    //  if(!q || !p) return false;

    //     return ( p->val== q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    // }
    
};