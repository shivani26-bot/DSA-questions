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
    bool isEvenOddTree(TreeNode* root) {
        queue<pair<int,TreeNode*>>q;
        int level=0;
        q.push({level,root});
        while(!q.empty()){
            int size=q.size();
           
int prevVal= level%2==0 ?INT_MIN :INT_MAX; //for even level, prevVal initialize ot Int_min and for odd level prevval initialize to int_max;
level++; //for next level
            while(size--){
TreeNode* node=q.front().second;
int currLevel=q.front().first;
q.pop();

//even level
if(currLevel%2==0 && (node->val%2==0 || node->val<=prevVal) ) return false;
else if(currLevel%2==1 && (node->val%2==1 || node->val>=prevVal) ) return false;
prevVal=node->val;
if(node->left) q.push({level,node->left});
if(node->right) q.push({level,node->right});
            }
        }
        return true;
    }
};