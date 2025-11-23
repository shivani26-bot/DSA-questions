/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
// void solve(TreeNode* root, vector<TreeNode*>& path1,vector<TreeNode*>& path2,vector<TreeNode*>& temp, TreeNode* p, TreeNode* q){
//     if(!root) return;
// temp.push_back(root);
// if(root->val==p->val){
//     for(int i=0;i<temp.size();i++){
//         path1.push_back(temp[i]);
//     }
// }
// if(root->val==q->val){
//     for(int i=0;i<temp.size();i++){
//         path2.push_back(temp[i]);
//     }
// }
// solve(root->left,path1,path2,temp,p,q);
// solve(root->right,path1,path2,temp,p,q);
// temp.pop_back();
// }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
// //      vector<TreeNode*>path1,path2,temp;
// //      solve(root,path1,path2,temp,p,q);
// //      int i=0;
// // while(i<path1.size() && i<path2.size()){
// //     if(path1[i]->val != path2[i]->val) break;
// //     i++;
// // }
// // return path1[i-1];
// if(!root) return NULL;
// if(root->val==p->val ||  root->val==q->val) return root;
// TreeNode* lst= lowestCommonAncestor(root->left,p,q);
// TreeNode* rst= lowestCommonAncestor(root->right,p,q);
// if(!lst) return rst;
// if(!rst) return lst;
// return root;
//     }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       
if(!root) return NULL;
if(root->val== p->val || root->val==q->val) return root;
       TreeNode* lst= lowestCommonAncestor(root->left,p,q);
       TreeNode* rst= lowestCommonAncestor(root->right,p,q);

// if(lst!=NULL && rst!=NULL) return root;
//  if(lst!=NULL) return lst;
//  return rst;

if(!lst) return rst;
 if(!rst) return lst;
 return root;
    }
};