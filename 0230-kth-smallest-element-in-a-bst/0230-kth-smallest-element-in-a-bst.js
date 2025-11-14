/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function(root, k) {
    let ans=0;
    // numbers are passed by value 
    let count=0;
function inorder( root, k,){

if(!root) return;
    inorder(root.left,k);
    count++;
if(count==k) {
    ans=root.val;
    return;
}
    
    inorder(root.right,k);
}


        inorder(root,k);
        return ans;
};