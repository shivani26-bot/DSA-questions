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
var allPossibleFBT = function(n) {
    const mp=new Map();
function solve( n){
    // even number of nodes can never form full binary tree 
    if(n%2==0) return [];

    if(n==1){
        const node= new TreeNode(0);
        return [node];
    }

if(mp.has(n)) return mp.get(n);
const result=[];
    for(let i=1;i<n;i+=2){
          const leftList=solve(i);
          const rightList=solve(n-i-1);
          for(const l of leftList){
            for(const r of rightList){
         const  root= new TreeNode(0);
         root.left=l;
         root.right=r;
         result.push(root);
            }
          }
    }
   mp.set(n,result);
    return result
}
 
        return solve(n);
    
};