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

//     const ans=[];
// function traverse(root){
//       if(!root) return;
//     traverse(root.left);
//     ans.push(root.val);
//     traverse(root.right);
// }
//     traverse(root);
 
//         for(let i=0;i<ans.length-1;i++){
//             if(ans[i]>=ans[i+1]){
//                return false;
//             }
          
//         }
//         return true;




   function isBst(root, min, max){
        // if we reach the end node then return true; 
        if(!root) return true;
        // for every node check whether it lies in min max range or not 
        if(root.val<=min || root.val>=max) return false;

// when we move to the left the current node should be max value because all the nodes in the left side must be smaller than it and when we move to the right the current node should be min value because all the nodes in the right side must be larger than it 
        return isBst(root.left, min, root.val) && isBst(root.right, root.val, max);
    }

 return isBst(root, -Infinity, Infinity);
};