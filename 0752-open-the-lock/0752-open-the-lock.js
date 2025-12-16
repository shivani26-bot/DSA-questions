/**
 * @param {string[]} deadends
 * @param {string} target
 * @return {number}
 */
var openLock = function(deadends, target) {
    

    function turnRight( c){
    return c==='9' ? '0': String.fromCharCode(c.charCodeAt(0)+1) ;

}

function turnLeft( c){
    return c==='0' ? '9' : String.fromCharCode(c.charCodeAt(0)-1);
}

function nextOptions( s){
const ans=[];
    for(let i=0;i<4;i++){
        // strings are immutable in js
        // let copy=s;
        //  copy[i]=turnRight(s[i]);
        //  ans.push(copy);
        //  copy[i]=turnLeft(s[i]);
        //  ans.push(copy);

        const arr=s.split("");
        arr[i]=turnRight(arr[i]);
        ans.push(arr.join(""));
         arr[i]=turnLeft(s[i]);
        ans.push(arr.join(""));

    }
    return ans;
}

const q=["0000"];
const visited= new Map();
visited.set("0000",true);

let level=0;
// once we have all the possible combination for a pattern , we need to see whether any of the combination is deadends or not
const deadendSet= new Set(deadends);
while(q.length>0){
    let sz= q.length;
    while(sz--){
        const s=q.shift();

        if(s==target) return level;
        if(deadendSet.has(s)) continue;
        for(const it of nextOptions(s) ){
            if(!visited.has(it)){
                 q.push(it);
                visited.set(it,true);
               
            }
        }
    }
    level++;
}
// return (visited[target]==true ? level : -1);
return -1;
};