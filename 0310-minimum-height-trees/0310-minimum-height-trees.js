/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[]}
 */
var findMinHeightTrees = function(n, edges) {
    const ans=[];//because reference doesn't change
if(n==1){
  ans.push(0);
    return ans;
}
const adjList=new Map();//const → Map reference never reassigned
const degree= Array(n).fill(0);
for(const it of edges){
    const u=it[0];
    const v=it[1];
    if(!adjList.has(u))
    adjList.set(u,[]);
    if(!adjList.has(v))
    adjList.set(v,[]);

    adjList.get(u).push(v);
 adjList.get(v).push(u);

    degree[u]++;
    degree[v]++;
}
const q=[];
for(let i=0;i<n;i++){
    if(degree[i]==1){
        q.push(i);
    }
}
while(n>2){
    let size=q.length;
    n-=size;
    while(size--){

        const ele=q.shift();
   
        for(const it of adjList.get(ele)){
            degree[it]--;
            if(degree[it]==1) q.push(it);
        }
    }
}


while(q.length>0){
    const ele=q.shift();
   
    ans.push(ele);
}
return ans;
};