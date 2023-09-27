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
vector<TreeNode*>ans;
void inorder(TreeNode* root){
if(!root) return ;
inorder(root->left);
ans.push_back(root);
inorder(root->right);
}
    void recoverTree(TreeNode* root) {
        inorder(root);
int countInstances=0;
TreeNode* n1;TreeNode* n2;TreeNode* n3;
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]->val > ans[i+1]->val){
                countInstances++;
                if(countInstances==1){
                    n1=ans[i];
                    n2=ans[i+1];
                }
                else if(countInstances==2){
                    n3=ans[i+1];
                }
            }
        }
        if(countInstances==1){
            int temp=n1->val;
n1->val=n2->val;
n2->val=temp;
        }
        else if(countInstances==2){
            int temp=n1->val;
            n1->val=n3->val;
            n3->val= temp;
        }

    }
};