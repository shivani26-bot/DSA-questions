/**
 * // Definition for a _Node.
 * function _Node(val, neighbors) {
 *    this.val = val === undefined ? 0 : val;
 *    this.neighbors = neighbors === undefined ? [] : neighbors;
 * };
 */

/**
 * @param {_Node} node
 * @return {_Node}
 */
var cloneGraph = function(node) {
  
     if(!node) return null;
      const mp=new Map();
function dfs(node, clone_node){

    for(const it of node.neighbors){
        if(!mp.has(it)){
            const clone= new Node(it.val);
            mp.set(it,clone);
            clone_node.neighbors.push(clone);
            dfs(it, clone);

        }
        else {
clone_node.neighbors.push(mp.get(it));
        }
    }
}


        // we will use map to store, old node and corresponding new node 
       const clone_node= new Node(node.val);
        mp.set(node,clone_node);

        dfs(node, clone_node);
        return clone_node;

};