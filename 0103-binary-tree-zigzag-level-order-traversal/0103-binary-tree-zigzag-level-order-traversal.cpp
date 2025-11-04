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
// time complexity : o(n)
// because each node is visited once, for every level pop the element from queue o(1) store it in temp o(1) push children in queue o(1)
// space: 
// in worst case for full binary tree, queue can hold upto max number of nodes in a level
// o(w) w is tree width
// In the worst case (balanced binary tree), w = O(n/2) = O(n).
// temp vector per level o(n)
// we store every node value in ans, o(n)
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        int level=0; //right to left
        while(!q.empty()){
                int size=q.size();
                    vector<int>temp(size);
              for(int i=0;i<size;i++){
  TreeNode* node= q.front();
            q.pop();
    int index= (level%2==0)?i:(size-i-1);
    
        temp[index]=node->val;
           
    
                  if(node->left) q.push(node->left);
                        if(node->right) q.push(node->right);
      
        }
 if(!temp.empty()){
    ans.push_back(temp);
 }
 level++;
                }
          return ans;

    }
};