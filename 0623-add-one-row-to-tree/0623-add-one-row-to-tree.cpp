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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // if(!root) {
        //     TreeNode *newTree= new TreeNode(val);
        //     return newTree;
        // }
 if(depth==1){
     TreeNode* newTree= new TreeNode(val);
     newTree->left=root;
     return newTree;
 }
 int depthCount=1;
 queue<TreeNode*>q;
 q.push(root);
 while(depthCount<depth-1){
     int size=q.size();
     
     for(int i=0;i<size;i++){
         TreeNode* curr= q.front();
     q.pop();
     if(curr->left) q.push(curr->left);
     if(curr->right) q.push(curr->right);
     }
    depthCount++;
 }
 while(!q.empty()){
     TreeNode* curr=q.front();
     q.pop();
 
     TreeNode* leftNode= new TreeNode(val);
       TreeNode* rightNode= new TreeNode(val);
      leftNode->left=curr->left;
         rightNode->right= curr->right;
       curr->left= leftNode;
     curr->right=rightNode;

     
 }
 return root;
    }
};