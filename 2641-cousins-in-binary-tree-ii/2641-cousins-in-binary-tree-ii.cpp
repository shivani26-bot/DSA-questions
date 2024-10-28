
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
public:
//     TreeNode* replaceValueInTree(TreeNode* root) {
// // levelsum-(siblingsum)= node value
// // find level sum using bfs
// // update each node
// queue<TreeNode*>q;
// vector<int>levelSum;
// q.push(root);
// while(!q.empty()){
//     int size=q.size();
//     int sum=0;
//     for(int i=0;i<size;i++){
//         TreeNode* node=q.front();
//         q.pop();
//         sum+=node->val;
//         if(node->left) 
//           q.push(node->left);
// if(node->right) 
//           q.push(node->right);

//     }
//     levelSum.push_back(sum);
// }

// q.push(root);
// root->val=0;
// int lvl=1;
// while(!q.empty()){
// int size=q.size();
// for(int i=0;i<size;i++){
//     TreeNode* curr= q.front();
//     q.pop();

//     int siblingSum=0;
//     siblingSum+=curr->left!=NULL? curr->left->val:0;
//     siblingSum+=curr->right!=NULL? curr->right->val:0;
//     if(curr->left){
//     curr->left->val= levelSum[lvl]-siblingSum;
//     q.push(curr->left);
// }
// if(curr->right){
//     curr->right->val= levelSum[lvl]-siblingSum;
//     q.push(curr->right);
// }
// }
// lvl++;

// }
// return root;
//     }

// one pass 
    TreeNode* replaceValueInTree(TreeNode* root) {
queue<TreeNode*>q;
// for every node find nextlevelsum 
q.push(root);
int levelSum=root->val;
while(!q.empty()){
    int size=q.size();
   
int nextLevelSum=0;
    for(int i=0;i<size;i++){
        TreeNode* node=q.front();
        q.pop();
      node->val=levelSum-node->val;
      int siblingSum=node->left!=NULL ? node->left->val:0;
      siblingSum+=node->right!=NULL ? node->right->val:0;
        if(node->left){ 
            nextLevelSum+=node->left->val;
        node->left->val=siblingSum;
          q.push(node->left);
          }
if(node->right){ 
     nextLevelSum+=node->right->val;
        node->right->val=siblingSum;
          q.push(node->right);
          }
    }
    levelSum=nextLevelSum;
}
return root;
    }
};