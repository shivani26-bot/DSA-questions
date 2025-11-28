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
 * @return {TreeNode}
 */
var reverseOddLevels = function(root) {
    const q=[];
let level=0;
q.push(root);
while(q.length>0){
   let size=q.length;
    const vec=[];
    while(size--){
       let node= q.shift();
        vec.push(node);
        if(node.left) q.push(node.left);
        if(node.right) q.push(node.right);
    
    }
    let l=0, r=vec.length-1;
    if(level%2==1){
    while(l<r){
        const temp=vec[l].val;
        vec[l].val=vec[r].val;
        vec[r].val=temp;
        l++;
        r--;
    }

    }
    level++;

}
return root;
};