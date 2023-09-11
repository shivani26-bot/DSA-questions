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
    int widthOfBinaryTree(TreeNode* root) {
         if(!root) return 0;
         queue<pair<TreeNode*,long long>>q;
         q.push({root,0});
      int ans=0;
         while(!q.empty()){
           
            long long minm=q.front().second;
            int size=q.size();
            long long first, last;
            for(int i=0;i<size;i++){
                 long long  curr_id=q.front().second- minm;
                TreeNode* curr=q.front().first;
                q.pop();
                if(i==0) first=curr_id;
                if(i==size-1) last=curr_id;
                if(curr){
                if(curr->left) q.push({curr->left,curr_id*2+1});
                if(curr->right) q.push({curr->right, curr_id*2+2});
                }
            }
            ans= max(ans,static_cast<int>(last-first+1));
         }
         return ans;
    }
};