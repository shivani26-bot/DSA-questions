/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
// the main problem in this question is when we get a target node, we can't go upward in order to find the node at distance k in upward direction.
// For BFS traversal we need queue
// mark the parent pointer of each node using bfs . while pushing node in queue mark its parent
void makeParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curr =q.front();
        q.pop();
        if(curr->left){
            parent[curr->left]=curr;
            q.push(curr->left);
        }
        if(curr->right){
            parent[curr->right]=curr;
            q.push(curr->right);

        }
    }
}

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        makeParents(root,parent);
        unordered_map<TreeNode*, bool>visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int distance=0;
        while(!q.empty()){
            int size=q.size();
        
            if(distance ==k) break;
            distance++;
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left]=true;
                }
                if(curr->right && !visited[curr->right]){

                    q.push(curr->right);
                    visited[curr->right]=true;
                }
                if(parent[curr] && !visited[parent[curr]]){
                    q.push(parent[curr]);
                    visited[parent[curr]]=true;
                }
            }
        }
        vector<int> result;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            result.push_back(curr->val);
        }
        return result;
    }
};