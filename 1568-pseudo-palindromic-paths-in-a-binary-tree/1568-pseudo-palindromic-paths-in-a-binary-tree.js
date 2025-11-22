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
var pseudoPalindromicPaths  = function(root) {
    
    let countPaths=0;
function solve(root, freq){
if(!root) return;
    freq[root.val]++;
if(!root.left && !root.right){
    //when we are at leaf node, just iterate through the freq array, and find out how many elements has occured odd times, 
    // if only one or less element has occured odd times it means its a palindromic path 
    let countOddOccurence=0;
    for(let i=0;i<10;i++){
        if(freq[i]%2==1) countOddOccurence++;
    }
    if(countOddOccurence<=1) countPaths++;
}
    solve(root.left,freq);
    solve(root.right,freq);
    freq[root.val]--;

}
     const freq= Array(10).fill(0);
   
 solve(root,freq);
    return countPaths;
};