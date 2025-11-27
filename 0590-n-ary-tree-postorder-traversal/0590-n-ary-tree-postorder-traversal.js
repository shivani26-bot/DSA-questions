/**
 * // Definition for a _Node.
 * function _Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */

/**
 * @param {_Node|null} root
 * @return {number[]}
 */
var postorder = function(root) {
    let ans=[];
     function dfs(root){
    if(!root) return;
    for(const child of root.children){
        dfs(child);
    }
    ans.push(root.val);
}
     dfs(root,ans);
     return ans;
};