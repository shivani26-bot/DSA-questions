/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
// class Solution {
// public:
// bool dfs(ListNode* temp,TreeNode* root){
//     if(!temp) return true;

//     if(!root || temp->val!=root->val) return false;



// return dfs(temp->next,root->left)||dfs(temp->next,root->right);
// }
//     bool isSubPath(ListNode* head, TreeNode* root) {
        

// if(!root) return false;
// ListNode* temp=head;
//     return (head->val==root->val && dfs(head,root)) || dfs(head,root->left)|| dfs(head,root->right);
//     }
// };


class Solution {
public:

// bool dfs(ListNode* head, ListNode* curr, TreeNode* root){
//       if(!curr)  return true;
//     if(!root) return false;


//  if(curr->val==root->val)
//     curr=curr->next;
// else if(head->val==root->val) head=head->next;
// else curr=head;

// return dfs(head,curr,root->left) || dfs(head,curr,root->right);

// }
//     bool isSubPath(ListNode* head, TreeNode* root) 
//     {
//              if(!root) return false;
//              if(!head) return false;

//              return dfs(head,head,root);
//     }

// bool dfs(ListNode* head,  TreeNode* root){
//       if(!head)  return true;
//     if(!root) return false;

// if(head->val!=root->val) return false;

// return dfs(head->next,root->left) || dfs(head->next,root->right);

// }
//     bool isSubPath(ListNode* head, TreeNode* root) 
//     {
//              if(!root) return false;
//              if(!head) return false;

//              return dfs(head,root)|| isSubPath(head,root->left)|| isSubPath(head,root->right);
//     }
// o(n*m) //m= linkedlist length, 
// root k hrr node se, linked list check ho rha hai 
bool dfs(ListNode* head, TreeNode* root){
    if(!head) return true;// means we reached the end of the linked list
if(!root) return false;

    if(head->val!=root->val) return false; 
return dfs(head->next,root->left)|| dfs(head->next,root->right);
}
    bool isSubPath(ListNode* head, TreeNode* root) 
    {
            if(!root) return false;
            if(!head) return false;
            return dfs(head,root) || isSubPath(head,root->left) || isSubPath(head,root->right);
    }
};