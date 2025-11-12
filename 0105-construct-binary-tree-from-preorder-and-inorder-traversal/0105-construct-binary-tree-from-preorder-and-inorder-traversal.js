/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
var buildTree = function(preorder, inorder) {
     const n=preorder.length;
    function solve(preorder,  inorder, inStart,inEnd, preStart, preEnd){
    if(inStart>inEnd) return null;
    const root= new TreeNode(preorder[preStart]);
    let i=inStart;
    for(;i<=inEnd;i++){
        if(inorder[i]==root.val) break;
    }
    let leftSize=i-inStart;
    let rightSize= inEnd-i;
    root.left= solve(preorder,inorder, inStart,i-1,preStart+1, preStart+leftSize);
    root.right= solve(preorder,inorder, i+1,inEnd,preEnd-rightSize+1, preEnd);
    return root;

}
    
       
        const inStart=0,inEnd=n-1;
        const preStart=0, preEnd=n-1;
        return solve(preorder,inorder, inStart, inEnd, preStart, preEnd);

};