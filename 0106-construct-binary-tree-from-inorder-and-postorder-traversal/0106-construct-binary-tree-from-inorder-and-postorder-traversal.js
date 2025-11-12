/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} inorder
 * @param {number[]} postorder
 * @return {TreeNode}
 */
var buildTree = function(inorder, postorder) {
      const n=inorder.length;
     
  function solve(inorder,postorder,inStart, inEnd, postStart, postEnd)
{
    if(inStart>inEnd) return null;
    const root=new TreeNode(postorder[postEnd]);
    let i=inStart;
    for(;i<=inEnd;i++){
if(inorder[i]==root.val) break; 
    }
    const leftSize=i-inStart;
    const rightSize=inEnd-i;
    root.left=solve(inorder,postorder, inStart,i-1,postStart,postStart+leftSize-1);
root.right= solve(inorder,postorder, i+1,inEnd,postEnd-rightSize,postEnd-1);
return root;
}
   
    
        return solve(inorder, postorder,0,n-1,0,n-1);

};