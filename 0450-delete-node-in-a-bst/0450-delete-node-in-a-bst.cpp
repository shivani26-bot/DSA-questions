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
// bool isLeaf(TreeNode* root){
//     return (!root->left && !root->right);
// }
// TreeNode* deleteLeaf(TreeNode* leafNode, TreeNode* parent){
// if (!parent || !leafNode) {
//         // Handle the case where either leafNode or parent is null.
//         return nullptr;
//     }
//     if(parent->left==leafNode){
//         parent->left=NULL;
//     }
//     else if(parent->right == leafNode){
//         parent->right=NULL;
//     }
    
//     return leafNode;
// }
// bool hasSingleChild(TreeNode* root){
//     return ((root->left && !root->right) || (!root->left && root->right));
// }
// TreeNode* deleteSingleChild(TreeNode* singleChildNode, TreeNode* parent){
//     if(singleChildNode->left){
//          if(parent->left==singleChildNode){
//              parent->left=singleChildNode->left;
//          }
//          else{
//              parent->right=singleChildNode->left;
//          }
//          singleChildNode->left=NULL;
//     }
//          else{
//                  if(parent->right==singleChildNode){
//              parent->right=singleChildNode->right;
//          }
//          else{
//              parent->left=singleChildNode->right;
//          }
//          singleChildNode->right=NULL;
//          }
//     return singleChildNode;
    
// }
// //either replace the node with largest element in lst or smallest elment in rst
// TreeNode* deleteDoubleChild(TreeNode* doubleChildNode,TreeNode* parent){
//     TreeNode* largestNode=doubleChildNode->left;
//     TreeNode* largestNodeParent=doubleChildNode;
//     while(largestNode->right){
//         largestNodeParent=largestNode;
//          largestNode=largestNode->right;
//     }
//     TreeNode* node1;
//     if(isLeaf(largestNode)){
//       node1=deleteLeaf(largestNode,largestNodeParent);
//     }
//     else{
//         node1=deleteSingleChild(largestNode,largestNodeParent);
//     }
//     if(parent && parent->left ==doubleChildNode) parent->left =node1;
//     else if(parent) parent->right =node1;
//     node1->left=doubleChildNode->left;
//     node1->right=doubleChildNode->right;
//     return doubleChildNode;
// }
// pair<TreeNode*,TreeNode*> getNodeAndParent(TreeNode* root,int key){
//        TreeNode* prev=NULL;
//     TreeNode* temp= root;
 
//     while(temp){
//         if(temp->val== key) break;
//         prev=temp;
//         if(temp->val < key) temp=temp->right;
//         else temp=temp->left;
//     }
//     return {temp,prev};
// }
//     TreeNode* deleteNode(TreeNode* root, int key) {
    
//         pair<TreeNode*, TreeNode*> p= getNodeAndParent(root,key);
//         if(!p.first) return root;

//     if (p.second == nullptr) {
//         // The node to be deleted is the root.
//         TreeNode* node = p.first;
//         if (isLeaf(node)) {
//             delete node;
//             return nullptr;  // Tree is now empty.
//         } else if (hasSingleChild(node)) {
//             TreeNode* newRoot = (node->left) ? node->left : node->right;
//             delete node;
//             return newRoot;
//         } else {
//             // Node has two children; replace it with the largest value from the left subtree.
//             TreeNode* largestNode = node->left;
//             TreeNode* largestNodeParent = node;
//             while (largestNode->right) {
//                 largestNodeParent = largestNode;
//                 largestNode = largestNode->right;
//             }

//             TreeNode* node1;
//             if (isLeaf(largestNode)) {
//                 node1 = deleteLeaf(largestNode, largestNodeParent);
//             } else {
//                 node1 = deleteSingleChild(largestNode, largestNodeParent);
//             }

//             if (node->left == largestNode) {
//                 node->left = node1;
//             } else {
//                 node->right = node1;
//             }

//             node1->left = node->left;
//             node1->right = node->right;

//             TreeNode* newRoot = (node->left) ? node->left : node->right;
//             delete node;
//             return newRoot;
//         }
//     } else {
//         // The node to be deleted is not the root.
//         TreeNode* node = nullptr;
//         if (isLeaf(p.first)) {
//             node = deleteLeaf(p.first, p.second);
//         } else if (hasSingleChild(p.first)) {
//             node = deleteSingleChild(p.first, p.second);
//         } else {
//             node = deleteDoubleChild(p.first, p.second);
//         }

//         delete node;
//         return root;
//     }
// }
    TreeNode* findMin(TreeNode* root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) {
        return root;  // Node not found, return the original tree.
    }

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with the key to be deleted found.
        if (!root->left) {
            // Node has only a right child or is a leaf.
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            // Node has only a left child.
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Node has two children; replace it with the in-order successor (smallest node in the right subtree).
        TreeNode* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }

    return root;
}
};