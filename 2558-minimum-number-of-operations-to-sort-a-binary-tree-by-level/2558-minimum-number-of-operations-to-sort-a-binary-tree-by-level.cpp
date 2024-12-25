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
int minOperations(vector<int>&vec){
    vector<int>sortedVec(begin(vec),end(vec));
    sort(begin(sortedVec),end(sortedVec));
    int swaps=0;
    unordered_map<int,int>mp;
    for(int i=0;i<vec.size();i++){
        mp[vec[i]]=i;
    }

for(int i=0;i<vec.size();i++){
    if(vec[i]==sortedVec[i]) continue;//no swap required
    else{
        swaps++;
        int swapIndex=mp[sortedVec[i]];
        mp[vec[i]]=swapIndex;
        mp[sortedVec[i]]=i;
        swap(vec[i],vec[swapIndex]);
       
    }
}
return swaps;
}
    int minimumOperations(TreeNode* root) {
        // at a time we have to process all the nodes of a level 
        // we can use bfs 
             // 0 1 2 3
        // vec={7,6,8,5}
    // sortvec={5,6,7,8}
//         map
//         7->0
//         6->1
//         8->2
//         5->3
// swap 7 with 5 in vec
// vec={5,6,8,7}
// sort={5,6,7,8}
// update map
//    map
//         7->3
//         6->1
//         8->2
//         5->0
//         swap 8 with 7
//         vec={5,6,7,8}
// sort={5,6,7,8}
// update map
//    map
//         7->2
//         6->1
//         8->3
//         5->0

        // only unique elements 
        // initially maintain index of all the elements of vec in map
// if index of a original element in vec doesn't match with index of that elementin sortvec then we should swap elements in vec and update the new index to the map
        queue<TreeNode*>q;
        q.push(root);
        int swaps=0;
        while(!q.empty()){
            int sz=q.size();
            vector<int>vec;
            while(sz--){
                TreeNode* node= q.front();
               q.pop();
                vec.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

             
            }

            swaps+=minOperations(vec);

        }
        return swaps;
    }
};