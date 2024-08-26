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
// vector<TreeNode*>ans;
// void dfs(TreeNode*root, unordered_set<int>&s,bool is_root){
// if(!root) return;
//     if(s.find(root->val)!=s.end()){
// //          if current node is present in the set then set it's left and right to true
// //   indicating that they will be the new root nodes 
// dfs(root->left,s,true);
// dfs(root->right,s,true);
//     }
//     else{
// if(is_root) ans.push_back(root);
// TreeNode* leftNode=root->left;
// TreeNode* rightNode=root->right;
// if(root->left){
//     if(s.find(root->left->val)!=s.end()) root->left=nullptr;
// }
// if(root->right){
//     if(s.find(root->right->val)!=s.end()) root->right=nullptr;
// }
// // normally traverse the root
//     dfs(leftNode,s,false);
//     dfs(rightNode,s,false);
      
//     }
// }
    // vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    // //   traverse the tree, and already make a map or set to keep track that particular
    // //   node is present in the to_delete array or not
    // // for every specific node check that whether it's left or right child is
    // // in the set or map, if either of the node is present in the map or set then 
    // // current node left or right will point to null 
    // // whenever we delete a node make sure that it's children are new root node 
    // unordered_set<int>s(to_delete.begin(),to_delete.end());
    // // true means that particular node is the root node 
    // dfs(root,s,true);
    // return ans;
    // }

TreeNode* dfs(TreeNode* root, unordered_set<int>&st,vector<TreeNode*>&result){
     if(!root) return NULL;

   root->left= dfs(root->left, st, result);
     root->right=dfs(root->right, st, result);
     if(st.find(root->val)==st.end()){
        return root;
     }
     else{
        if(root->left!=NULL){
            result.push_back(root->left);
        }
        if(root->right!=NULL){
            result.push_back(root->right);
        }

        return NULL;
     }
}


vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    // [1,2,3,4,5,6,7,null,null,null,null,10,11]
    // node to delete[3,6,5]
    // if we traverse through the tree from top to bottom , and delete
    // 3 first then we won't be able to delete 6 further
    // instead use dfs or bottom up, delete the bottom most nodes, and then go upwards
// while going upward if element is present in to_delete array then delete it and return null to it's parent
// if the node deleted has left and right child then we need to store them as the root of two different new trees
// next delete the element and return null 
// once the dfs traversal is over, must check whether the main root of the original tree is present in to_delete or not 
// we store all the elements in set so that we can avoid again and again
// traversal of to_delete array

vector<TreeNode*>result;
unordered_set<int>st(to_delete.begin(),to_delete.end());
dfs(root,st,result);

if(st.find(root->val)==st.end()){
    result.push_back(root);
}
return result;
}
};

