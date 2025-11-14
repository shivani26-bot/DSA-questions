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
 * @return {boolean}
 */
var isValidBST = function(root) {

    const ans=[];
function traverse(root){
      if(!root) return;
    traverse(root.left);
    ans.push(root.val);
    traverse(root.right);
}
    traverse(root);
 
        for(let i=0;i<ans.length-1;i++){
            if(ans[i]>=ans[i+1]){
               return false;
            }
          
        }
        return true;
};