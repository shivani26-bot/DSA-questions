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
    // long long kthLargestLevelSum(TreeNode* root, int k) {
        
    //     queue<TreeNode*>q;
    //     q.push(root);
    //     vector<long long>levelSum;
    //     while(!q.empty()){
    //         int size=q.size();
    //         long long sum=0;
    //         while(size--){
    //             TreeNode* node=q.front();
    //             q.pop();
    //            sum+=node->val;
    //            if(node->left){
    //               q.push(node->left);
    //            }
    //            if(node->right){
    //             q.push(node->right);
    //            }
    //         }
    //         levelSum.push_back(sum);
    //     }
    //        if(levelSum.size()<k) return -1;
    //     sort(levelSum.begin(),levelSum.end(),greater<long long>());// sort in descending order
     
    //     return levelSum[k-1];
    // }


     long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long,vector<long long>, greater<long long>>minheap;//minheap

        queue<TreeNode*>q;
        q.push(root);
  
        while(!q.empty()){
            int size=q.size();
            long long sum=0;
            while(size--){
                TreeNode* node=q.front();
                q.pop();
               sum+=node->val;
               if(node->left){
                  q.push(node->left);
               }
               if(node->right){
                q.push(node->right);
               }
            }
     minheap.push(sum);
     if(minheap.size()>k) minheap.pop();
        }
return minheap.size()<k ?-1:minheap.top();
    }
};