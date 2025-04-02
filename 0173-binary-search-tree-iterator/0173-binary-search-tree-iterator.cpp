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
class BSTIterator {
public:
vector<int>inorder;
int count=0;
void traverse(TreeNode* root){
if(!root) return ;
    traverse(root->left);
    inorder.push_back(root->val);
    traverse(root->right);
}
    BSTIterator(TreeNode* root) {
        traverse(root);
    }
    
    int next() {
        return inorder[count++];
    }
    
    bool hasNext() {
        return count<inorder.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */