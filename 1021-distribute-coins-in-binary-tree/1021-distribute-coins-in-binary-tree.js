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
var distributeCoins = function(root) {
    
let moves=0;
function solve(root, parent){
if(!root) return ;
 solve(root.left,root);
 solve(root.right, root);

 if(root.val>=1){
    let extraCoins= root.val-1;
    parent.val+=extraCoins;//if extra coins are present at the child it will be added to parent
    root.val=1;
    moves+=extraCoins;
 }
 else{
    let neededCoins=1+Math.abs(root.val);
    parent.val-=neededCoins;// if no extra coins are there with the child and child needs them then parent will have to give it to child hence it will be subtracted from parent
    root.val=1;
    moves+=neededCoins;
 }
}
 solve(root,root);
          return moves;
};