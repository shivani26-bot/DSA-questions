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
 * @return {boolean}
 */
var isCompleteTree = function(root) {
  function bfs(root){
   const q=[];
    q.push(root);
      let foundNull=false;
    while(q.length>0){
      const node= q.shift();
      

      if(!node) {
        foundNull=true; //if node is null mark it true
      }
      else{ //if node is present then check whether have seen null in past or not if yes then return false other wise push the left and right child 
        if(foundNull) return false;
        q.push(node.left);
        q.push(node.right);// if there is null node it pushes 0, if there is node it pushes the address of the node
        // cout<<node->left<<" "<<node->right;
      }
        
    }
    return true;
}
 return bfs(root);
};