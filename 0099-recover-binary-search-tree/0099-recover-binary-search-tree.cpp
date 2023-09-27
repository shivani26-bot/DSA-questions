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
// void inorder(TreeNode* root){
// if(!root) return ;
// inorder(root->left);
// ans.push_back(root);
// inorder(root->right);
// }
void inorder(TreeNode* root, TreeNode* &prev,TreeNode* &n1,TreeNode* &n2,TreeNode* &n3, int &countInstances){
    if(!root)return;
    inorder(root->left,prev,n1,n2,n3,countInstances);
        if(!prev) prev=root;
        else{
                  if(root->val < prev->val){
                      countInstances++;
                      if(countInstances==1){
                          n1=prev;
                          n2=root;
                      }
                      else if(countInstances==2){
                          n3=root;
                      }
                  } 
                  prev=root;
        }

        inorder(root->right,prev,n1,n2,n3,countInstances);

}
    void recoverTree(TreeNode* root) {
//         inorder(root);
// int countInstances=0;
// TreeNode* n1;TreeNode* n2;TreeNode* n3;
//         for(int i=0;i<ans.size()-1;i++){
//             if(ans[i]->val > ans[i+1]->val){
//                 countInstances++;
//                 if(countInstances==1){
//                     n1=ans[i];
//                     n2=ans[i+1];
//                 }
//                 else if(countInstances==2){
//                     n3=ans[i+1];
//                 }
//             }
//         }
//         if(countInstances==1){
//             int temp=n1->val;
// n1->val=n2->val;
// n2->val=temp;
//         }
//         else if(countInstances==2){
//             int temp=n1->val;
//             n1->val=n3->val;
//             n3->val= temp;
//         }

// approach 2: optimize space
// Instead of storing all the elements in vector and checking the adjacent pair, 
// we can also maintain a variable which keeps track whenever we are at root what
//  was the previous node or inorder predecessor.
// Idea is similar to binary tree is bst or not depending on sortedness of inorder traversal.

 int countInstances=0;
TreeNode* n1=NULL;TreeNode* n2=NULL;TreeNode* n3=NULL;
TreeNode* prev=NULL;
inorder(root,prev,n1,n2,n3,countInstances);
 if (countInstances == 1) {
        // If only one pair of nodes is swapped, swap n1 and n2 values to correct the BST.
        swap(n1->val, n2->val);
    } else if (countInstances == 2) {
        // If two pairs of nodes are swapped, swap n1 and n3 values to correct the BST.
        swap(n1->val, n3->val);
    }
    }
};