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
 * @return {number[]}
 */
var largestValues = function(root) {
     let ans=[];
        if(!root) return ans;
        let q=[];
        q.push(root);

        while(q.length>0){
            let sz=q.length;
           let maxm=-Infinity;
            while(sz--){
                const node=q.shift();
               
               
                if(node.val>maxm){
                    maxm=node.val;
                }
                if(node.left) q.push(node.left);
                if(node.right) q.push(node.right);
            }
ans.push(maxm);

        }
        return ans;
};