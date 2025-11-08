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
 * @param {number} key
 * @return {TreeNode}
 */
var deleteNode = function(root, key) {
     if(!root) return root;
function findMin( root){
    while(root.left){
        root=root.left;
    }
    return root;
}
      if(root.val>key) root.left= deleteNode(root.left, key);
      else if(root.val<key) root.right= deleteNode(root.right,key);
      else{
       if(!root.left){
       let temp=root.right;
        delete root;
        return temp;
       }
        else if(!root.right){
        let temp=root.left;
        delete root;
        return temp;
       }
       else{
        let temp= findMin(root.right);
        root.val=temp.val;
        root.right= deleteNode(root.right,temp.val);
       }
      }
      return root;
};