/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[][]} descriptions
 * @return {TreeNode}
 */
var createBinaryTree = function(descriptions) {
  const mp=new Map();
const childNodes=new Set();
for(const it of descriptions){
    let parent=it[0];
    let child=it[1];
    let isLeft=it[2];
    if(!mp.has(parent)){
        mp.set(parent, new TreeNode(parent));
    }
 if(!mp.has(child)){
        mp.set(child, new TreeNode(child));
    }
    if(isLeft==1){
      let p=  mp.get(parent);
      let c=  mp.get(child);
        p.left=c;
        // mp.get(parent).left=mp.get(child);
    }
    else{
        mp.get(parent).right=mp.get(child);
    }
    childNodes.add(child);
}
for(const it of descriptions){
    // check whether parent is present in child nodes set or not
    // the element which is not present in child nodes is the answer, the parent root node is never a child of any other node 
  const parent=it[0];
    if(!childNodes.has(parent)) return mp.get(parent);
}
return null;
};