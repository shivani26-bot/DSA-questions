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
var isEvenOddTree = function(root) {
    const q=[];
        let level=0;
        q.push(root);
        while(q.length>0){
           let size=q.length;
           
let prevVal= level%2==0 ?-Infinity:Infinity; 
            while(size--){
const node=q.shift();
//even level
if(level%2==0 && (node.val%2==0 || node.val<=prevVal) ) return false;
else if(level%2==1 && (node.val%2==1 || node.val>=prevVal) ) return false;
prevVal=node.val;
if(node.left) q.push(node.left);
if(node.right) q.push(node.right);
            }
            level++;
        }
        return true;
};