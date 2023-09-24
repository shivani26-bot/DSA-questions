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
vector<int> nextLargerElement(vector<int>preorder){
vector<int>nextGreaterElement(preorder.size());
stack<int>st;
st.push(0);
for(int i=1;i<preorder.size();i++){
    while(!st.empty() && preorder[st.top()] <preorder[i]){
        // int x=st.top();
        // st.pop();
        // nge[x]=preorder[i];
       nextGreaterElement[st.top()]=i;
        st.pop();
    }
    st.push(i);
}
while(!st.empty()){
    nextGreaterElement[st.top()]=preorder.size();
    st.pop();
}
return nextGreaterElement;
}
TreeNode* makeBST(vector<int>&preorder,int i,int j,vector<int>nge){
if(i>j) return NULL;
    TreeNode* node= new TreeNode(preorder[i],NULL,NULL);
     node->left=makeBST(preorder,i+1,nge[i]-1,nge);
     node->right=makeBST(preorder,nge[i],j,nge);
     return node;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> nge= nextLargerElement(preorder);
        return makeBST(preorder,0,preorder.size()-1,nge);


    }
};