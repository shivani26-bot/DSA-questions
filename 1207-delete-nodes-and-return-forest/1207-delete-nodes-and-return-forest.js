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
 * @param {number[]} to_delete
 * @return {TreeNode[]}
 */
var delNodes = function(root, to_delete) {
   
const st= new Set(to_delete);
let result=[];
function solve(root){
if(!root) return null;
root.left= solve(root.left);
root.right=solve(root.right);
if(!st.has(root.val)){
    return root;
}
else{
    if(root.left){
        result.push(root.left);
        
    }
    if(root.right){
        result.push(root.right);
    }
    return null;
}
}



solve(root);
if(!st.has(root.val)){
    //check the final main root , whether it's present in set or not
    result.push(root);
}
return result;  
};