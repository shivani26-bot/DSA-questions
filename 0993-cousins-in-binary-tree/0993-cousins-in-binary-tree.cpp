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
// void solve(TreeNode* root, TreeNode* prev, int level,int x,int &xLevel, TreeNode*& parent){
// if(!root) return;

// if(root->val==x){
//     parent=prev;
//     xLevel=level;
//     return;
// }
//     solve(root->left,root,level+1,x,xLevel,parent);
//     solve(root->right,root,level+1,x,xLevel,parent);
// }
//     bool isCousins(TreeNode* root, int x, int y) {
//     //    dfs approach 
//     //  find parent for each x and y and also find level for each of them 
//     int aLevel=0;
//     int bLevel=0;
//     TreeNode* aParent=NULL;
//     TreeNode* bParent=NULL;
//     solve(root,NULL,0,x,aLevel,aParent);
//     solve(root,NULL,0,y,bLevel,bParent);
//     return (aLevel==bLevel && aParent!=bParent );
//     }


    bool isCousins(TreeNode* root, int x, int y) {
    //    bfs approach 
    // maintain node and parent in the queue
   queue<pair<TreeNode*,TreeNode*>>q;
   q.push({root,NULL});
   while(!q.empty()){
    int size=q.size();
    TreeNode* parentX=NULL;
    TreeNode* parentY=NULL;
    while(size--){
        TreeNode* currNode=q.front().first;
        TreeNode* parent=q.front().second;
q.pop();
if(currNode->val==x) parentX=parent;
if(currNode->val==y) parentY=parent;

        if(currNode->left) q.push({currNode->left,currNode});
        if(currNode->right) q.push({currNode->right,currNode});
    }
    //for each level, if both the elements are present at same level then after the level is over, just check we find parent for x and y both or not, if parent for both are not same then return true, if either of them has parent then return false;
    if(parentX && parentY) return parentX!=parentY;
    // if(parentX || parentY) return false;
   }
   return false;
    }
};