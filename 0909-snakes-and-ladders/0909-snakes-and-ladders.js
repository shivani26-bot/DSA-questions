/**
 * @param {number[][]} board
 * @return {number}
 */
var snakesAndLadders = function(board) {
     const n=board.length;

   function getCoord( num){
    // / in JavaScript gives a floating-point numbe
    const rt=Math.floor((num-1)/n); // row from top
    const rb= (n-1)- rt;//row from bottom
    let col= (num-1)%n;
    // for right to left 
    // (n-1) - ((val-1)%n)
    if((n%2==1 && rb%2==1) || (n%2==0 && rb%2==0))
     col=n-1-col;

     return [rb,col];

}

   const q=[];
    q.push(1);
    let steps=0;
    const visited=Array.from({length:n},()=>Array(n).fill(false));
    visited[n-1][0]=true;
    while(q.length>0){
        let sz=q.length;
        while(sz--){
       let x=q.shift();
     
        if(x==n*n) return steps;
        for(let i=1;i<=6;i++){
            let adjx= x+i;
            if(adjx>n*n) break;
           const [r,c]=getCoord(adjx);
           
           if(visited[r][c]) continue;
           visited[r][c]=true;
      
        if(board[r][c]!=-1){
              q.push(board[r][c]);
           } 
           else{ //if board[r][c]==-1
            q.push(adjx);
           } 
        }
            }
         steps++;
    
    }
    return -1; //if x==n*n con
};