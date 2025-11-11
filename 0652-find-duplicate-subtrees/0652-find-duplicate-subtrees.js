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
 * @return {TreeNode[]}
 */
var findDuplicateSubtrees = function(root) {
      const mp= new Map();
       const ans=[];
   function dfs(root){
if(!root) return "N";
let s=(root.val).toString()+","+dfs(root.left)+","+dfs(root.right);
if(mp.get(s)==1) ans.push(root);
mp.set(s,(mp.get(s) || 0)+1);
return s;
}
   

        dfs(root);
        return ans;

    
};