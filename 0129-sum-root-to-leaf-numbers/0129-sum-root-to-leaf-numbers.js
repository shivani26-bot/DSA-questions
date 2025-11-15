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
 * @return {number}
 */
var sumNumbers = function(root) {
function solve(root, num){
if(!root) return 0;
if(!root.right && !root.left){
     num=num*10+root.val;
     return num;
}
    num=num*10+root.val;
    const l=solve(root.left,num);
    const r=solve(root.right,num);
    return l+r;
}
    return solve(root,0);
};