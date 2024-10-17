class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
       if(a>0) pq.push({a,'a'});
       if(b>0)  pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});
     
string result;
while(!pq.empty() )
{

// auto [el ,currCount]=pq.top();
 char el=pq.top().second;
    int currCount=pq.top().first;
   pq.pop();
   if(result.size()>=2 && result[result.size()-1]==el && result[result.size()-2]==el){
    
    if(pq.empty()) break;
    // auto [newel ,newcurrCount]=pq.top();
    char newel=pq.top().second;
    int newcurrCount=pq.top().first;
   pq.pop();
    result+=newel;
   newcurrCount--;
   
  
   if(newcurrCount>0)
   pq.push({newcurrCount,newel});

    pq.push({currCount,el});
   }
   else{
   result+=el;
   currCount--;
   if(currCount>0)
   pq.push({currCount,el});
   }
   
}

        return result;




    }
};