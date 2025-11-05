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
var diameterOfBinaryTree = function(root) {
      let result = 0; // this will store the max diameter found so far

  function dfs(node) {
    if (!node) return 0; // base case: height of null node is 0

    const left = dfs(node.left);  // height of left subtree
    const right = dfs(node.right); // height of right subtree

    // diameter through this node = left height + right height
    result = Math.max(result, left + right);

    // return height of current subtree
    return 1 + Math.max(left, right);
  }

  dfs(root);
  return result;
};