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
 * @param {number} x
 * @param {number} y
 * @return {boolean}
 */
var isCousins = function(root, x, y) {
    const q=[];
   q.push([root,null]);
   while(q.length>0){
   let size=q.length;
 let parentX=null;
    let parentY=null;
    while(size--){
        const [currNode,parent]=q.shift();
    

if(currNode.val==x) parentX=parent;
if(currNode.val==y) parentY=parent;

        if(currNode.left) q.push([currNode.left,currNode]);
        if(currNode.right) q.push([currNode.right,currNode]);
    }
    //for each level, if both the elements are present at same level then after the level is over, just check we find parent for x and y both or not, if parent for both are not same then return true, if either of them has parent then return false;
    if(parentX && parentY) return parentX!=parentY;
    if(parentX || parentY) return false;
   }
   return false;
};