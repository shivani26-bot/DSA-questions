/**
 * @param {number} n
 * @param {number} headID
 * @param {number[]} manager
 * @param {number[]} informTime
 * @return {number}
 */
var numOfMinutes = function(n, headID, manager, informTime) {
     const adjList= new Map();
     
        for(let i=0;i<manager.length;i++){
            const u=manager[i];
            // int time=informTime[u];// time required by the manager to inform his subordinated
           const v=i;

            if(u==-1) continue;
            if(!adjList.has(u)) adjList.set(u,[]);
            adjList.get(u).push(v);
        }
    
const q=[{curr_employee:headID,curr_time: 0}]  //stores the node, start from headNode
let  maxTime=0;

      while(q.length>0){
    const {curr_employee, curr_time}=q.shift();
    //    const curr_employee=q.shift().head;
    //    const curr_time=q.shift().time;///time taken by node to spread the news to his subordinates
    
maxTime=Math.max(maxTime,curr_time);
      
   

if(adjList.has(curr_employee)){
for(const it of adjList.get(curr_employee)){
   
    const adjTime=curr_time+informTime[curr_employee];
q.push({curr_employee:it,curr_time:adjTime});
}
}

        }

return maxTime;
};