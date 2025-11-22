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
 * @return {string}
 */
var smallestFromLeaf = function(root) {

    let ans;
function solve(root, s){
    if(!root) return;

    s=String.fromCharCode('a'.charCodeAt(0)+root.val)+s;
if(!root.left && !root.right){
    if(!ans||ans>s) ans=s;
    return;
}

    solve(root.left,s);
    solve(root.right,s);
}
      solve(root,"");
        return ans; 
};