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
    TreeNode* replaceValueInTree(TreeNode* root) {
        // store total sum of each level
        vector<int>levelSum;
            queue<TreeNode*>q;
            q.push(root);
            while(!q.empty()){
                int size=q.size();
                  int sum=0;
                while(size--){
                    TreeNode* node= q.front();
                    q.pop();
          sum+=node->val;
          if(node->left) q.push(node->left);
          if(node->right) q.push(node->right);
                }
                levelSum.push_back(sum);
            }
            // levelSum= 5, 13,18 //according to ex:1 
            q.push(root);
            root->val=0;
            int lvl=1;
            while(!q.empty()){
                int size=q.size();
                while(size--){
TreeNode* node= q.front();
q.pop();

                    int siblingSum=0;
                    siblingSum+= node->left !=NULL ?node->left->val : 0;
siblingSum+= node->right !=NULL ?node->right->val : 0;

if(node->left){
    q.push(node->left);
    node->left->val=levelSum[lvl]-siblingSum;
}
if(node->right){
    q.push(node->right);
    node->right->val=levelSum[lvl]-siblingSum;
}
                }
                lvl++;
            }
            return root;
    }
};