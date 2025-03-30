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
vector<int>travel(TreeNode* root){
if(!root) return {0,0};

   vector<int>left_node_choices= travel(root->left);
  vector<int>right_node_choices=  travel(root->right);
  vector<int>options(2);
  //rob it
  options[0]=root->val+left_node_choices[1]+right_node_choices[1];
  //skip it
options[1]= max(left_node_choices[0],left_node_choices[1])+max(right_node_choices[0],right_node_choices[1]);

return options;
}
    int rob(TreeNode* root) {
//         for each of the node we have 2 option either rob it or skip it
//                           A
//                 B                  C
//             Brob|Bskip         Crob|Cskip
//             if we choose to rob, A then we will be choosing, Bskip + Cskip, because we can't rob adjacent nodes
//             if we choose to skip A, we have options, either we can rob B or C or both ,then ans of node A will be, max(Brob,Bskip) + max(Crob,Cskip)

//             1
//       9           2
//  3             8      7

//  process:
//             19|24
//              1  
//    9|3                2|15
//       9            2  
//   3             8      7
//  3|0           8|0    7|0
//  we traverse through the tree, for node 3,if we take it 3 otherwise 0, 
//  node 8, if we take it 8 otherwise 0, 
//  node 7, if we take it 7 otherwise 0, 
//  node 2 , if we take it, 2, other wise 8+7=15, max(8,0)+max(7,0)
//  node 9, if we take it 9, other wise max(3,0)=3
//  node 1, if we take it 1+3+15=19, if we choose node 1, we can only choose the skip value of the child nodes as it will tell what was the value of money collected when both the children were skipped, if we skip the node 1, max(9,3)+max(2,15)= 24
vector<int>options=travel(root);
return max(options[0],options[1]);
// rob, skip 



        
    }
};