/**
 * @param {number} n
 * @param {number[][]} trust
 * @return {number}
 */
var findJudge = function(n, trust) {
      const  indeg =Array(n+1).fill(0);
         const out= Array(n+1).fill(0);
        //  for(const it of trust){
        //     out[it[0]]++;
        //     indeg[it[1]]++;
        //  }
          for(const [a,b] of trust){
            out[a]++;
            indeg[b]++;
         }
         for(let i=1;i<=n;i++){
            if(indeg[i]==n-1 && out[i]==0) return i;
         }
         return -1;
};