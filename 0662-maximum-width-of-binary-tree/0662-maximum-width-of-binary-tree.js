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
var widthOfBinaryTree = function(root) {
     const q=[];
        q.push({node:root,idx:0});
        let maxWidth=0;
        while(q.length>0){
            let size=q.length;
const startIdx= q[0].idx;
const endIdx= q[size-1].idx;
maxWidth= Math.max(maxWidth, endIdx-startIdx+1);
            while(size--){
                const {node,idx}= q.shift();
      normalizedIdx=idx-startIdx;//to prevent overflow
             
                if(node.left) q.push({node:node.left,idx:2*normalizedIdx+1});
                if(node.right) q.push({node:node.right,idx:2*normalizedIdx+2});

            }
        }
        return maxWidth;
};