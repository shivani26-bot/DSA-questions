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
 * @param {number} low
 * @param {number} high
 * @return {TreeNode}
 */
var trimBST = function(root, low, high) {
      if(!root) return null;
    function solve( root, low, high){
      if(!root) return null;
      if(root.val<low) return solve(root.right,low,high);
      if(root.val>high) return solve(root.left, low, high);
      root.left=solve(root.left,low,high);
      root.right=solve(root.right,low,high);
      return root;
}
   
      
        return solve(root,low,high);

};