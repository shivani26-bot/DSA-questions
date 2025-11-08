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
var tree2str = function(root) {
     let ans = root.val.toString();
		if (root.left) //left side check
			ans += "(" + tree2str(root.left) + ")";
		if (root.right) { //right side check
			if (!root.left) ans += "()"; //left side not present, but right side present
			ans += "(" + tree2str(root.right) + ")"; 
		}
		return ans;
};