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
 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if(!root) return NULL;
        if(root->val ==p->val || root->val ==q->val) return root;
        TreeNode* lst= lowestCommonAncestor(root->left,p,q);
        TreeNode* rst= lowestCommonAncestor(root->right,p,q);
        if(!lst) return rst;
        if(!rst) return lst;
        return root;
 }
TreeNode* findLCAOfLeaves(vector<TreeNode*> deepLeaves, TreeNode* root){
    if(deepLeaves.size()==1) return deepLeaves[0];
    TreeNode* lca= deepLeaves[0];
    for(int i=1;i<deepLeaves.size();i++){
      lca=lowestCommonAncestor(root,lca, deepLeaves[i]);
    }
    return lca;
}
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
      vector<TreeNode*>deepLeaves;
        while(!q.empty()){
           int c=q.size();
           if(deepLeaves.size()>0) deepLeaves.clear();
           for(int i=0;i<c;i++){
               TreeNode* curr= q.front();
               q.pop();
               deepLeaves.push_back(curr);
               if(curr->left) q.push(curr->left);
               if(curr->right) q.push(curr->right);
           }
        }
     
        TreeNode* ans= findLCAOfLeaves(deepLeaves,root);
        return ans;
    }
};