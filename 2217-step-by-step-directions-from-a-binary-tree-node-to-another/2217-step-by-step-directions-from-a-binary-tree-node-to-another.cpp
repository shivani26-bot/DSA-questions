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
// [3,5,1,6,2,0,8,null, null ,7,4]
// p=5 q=4
// if we get leftN=p, rightN=q then root is the answer
// leftN from left side of tree 
// rightN from right side of tree
// if leftN=p, rightN=null then not null value is answer
// if leftN=NULL, rightN=q then rightN is answer
// it is possible the current root itself is p or q then return that root itself
//     TreeNode* LCA(TreeNode* root, int p, int q) {
// if(!root) return NULL;
// if(root->val==p ||  root->val==q) return root;
// TreeNode* lst= LCA(root->left,p,q);
// TreeNode* rst= LCA(root->right,p,q);
// if(!lst) return rst;
// if(!rst) return lst;
// return root; // when lst and rst both are not null
//     }
//     string lcaToStart,lcaToEnd;
//     void dfs(TreeNode* node,string& pathString, int p, int q){
//          if(!node) return;
//          if(node->val==p) lcaToStart=pathString;
//          if(node->val==q) lcaToEnd=pathString;


//          pathString.push_back('L');
//          dfs(node->left,pathString,p,q);
//         //  cout<<pathString<<endl;
//          pathString.pop_back();
// // cout<<pathString<<endl;
//             pathString.push_back('R');
//          dfs(node->right,pathString,p,q);
//          pathString.pop_back();
//     }
//     string getDirections(TreeNode* root, int startValue, int destValue) {
//     //    find the lca of start val and dest val, from start val to lca take u direction and from lca to dest val take l or r depending on the direciton 
// TreeNode* lcaNode=LCA(root,startValue,destValue);
// // call a dfs traversal starting from lca and empty pathstring 
// string pathString="";
// dfs(lcaNode,pathString,startValue,destValue);
// for(auto &ch: lcaToStart) ch='U';
// return lcaToStart+lcaToEnd;
//     }

TreeNode* lca(TreeNode* root, int p, int q){
    if(!root) return NULL;
    if(root->val==p || root->val ==q) return root;
    TreeNode* lst= lca(root->left, p,q);
    TreeNode* rst= lca(root->right, p, q);

    if(lst && rst) return root;
    if(lst) return lst;
    return rst;
}
string lcaToSrc="";
string lcaToDest="";
void path(TreeNode* node, string& pathString, int p, int q){
if(!node) return ;
if(node->val==p){
   lcaToSrc=pathString;
}
if(node->val==q){
    lcaToDest=pathString;
}
    pathString.push_back('L');
    path(node->left, pathString, p,q);
    pathString.pop_back();
    pathString.push_back('R');
    path(node->right,pathString, p,q);
    pathString.pop_back();
}
    string getDirections(TreeNode* root, int startValue, int destValue) {
TreeNode* lcaNode= lca(root,startValue,destValue);
string pathString="";
path(lcaNode,pathString,startValue,destValue);
// for start to lca it will be U 
for(auto &ch: lcaToSrc) ch='U';
return lcaToSrc+lcaToDest;
    }
};