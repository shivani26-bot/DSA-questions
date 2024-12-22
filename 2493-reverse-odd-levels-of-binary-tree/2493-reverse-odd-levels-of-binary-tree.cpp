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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
       
int level=0;
        while(!q.empty()){
            int sz=q.size();
              vector<TreeNode*>vec;
            while(sz--){
               
               TreeNode* node= q.front();
               q.pop();
               vec.push_back(node);
               if(node->left) q.push(node->left);
               if(node->right) q.push(node->right);
            }

if(level%2==1){ //odd level
int l=0,r=vec.size()-1;
while(l<r){
    int temp=vec[l]->val;
    vec[l]->val=vec[r]->val;
    vec[r]->val=temp;
    l++;
    r--;
}
}
            level++;
        }
        return root;
    }
};