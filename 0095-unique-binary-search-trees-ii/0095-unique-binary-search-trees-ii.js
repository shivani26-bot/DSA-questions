/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number} n
 * @return {TreeNode[]}
 */
var generateTrees = function(n) {
    if(n==0) return [];
  const mp=new Map();
function solve( start,  end){
 
   if(start>end) return [null];
   if(start==end) {
    const root= new TreeNode(start);
    return [root];
    }
       const key=  `${start}-${end}`;
    if(mp.has(key))
    return mp.get(key);

const result=[];
   for(let i=start;i<=end;i++){
    const leftList= solve(start,i-1);
    const rightList=solve(i+1,end);
for(const leftRoot of leftList){
    for(const rightRoot of rightList){
      const root= new TreeNode(i);
        root.left=leftRoot;
        root.right=rightRoot;
        result.push(root);
    }
}
   }
  mp.set(key,result);
  return result;
}
     return solve(1,n);
};