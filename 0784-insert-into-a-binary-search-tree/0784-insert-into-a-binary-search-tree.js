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
 * @param {number} val
 * @return {TreeNode}
 */
var insertIntoBST = function(root, val) {
   if(!root) { 
        const newNode= new TreeNode(val);
        return newNode;
        }  
function dfs(root, parent, val){
    if(!root){
    const newNode= new TreeNode(val);
    if(parent.val>val) parent.left= newNode;
    else if(parent.val<val) parent.right= newNode;
    return;
}

    if(root.val>val){
        dfs(root.left, root, val);
    }
    if(root.val<val){
        dfs(root.right, root, val);
    }
}

         dfs(root,null,val);
       return root;
};