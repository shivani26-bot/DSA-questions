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
var findBottomLeftValue = function(root) {
    
        const q=[];
        q.push(root);
     let leftnode;
        while(q.length>0){
          let size=q.length;
         leftnode= q[0].val; //don't use shift here
            while(size--){
                const node= q.shift();
                
if(node.left) q.push(node.left);
if(node.right) q.push(node.right);
            }
        }
        return leftnode;
};