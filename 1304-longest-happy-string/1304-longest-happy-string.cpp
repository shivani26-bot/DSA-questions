class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // always start with character with highest frequency , it will help in forming the longest string
    // push the element {freq, char}  in priority queue max heap
    priority_queue<pair<int,char>>pq;

    if(a>0) pq.push({a,'a'});
    if(b>0) pq.push({b,'b'});
    if(c>0) pq.push({c,'c'});
string result;
    while(!pq.empty()){
auto [currCount,ele]=pq.top();
pq.pop();
        if(result.size()>=2 && result[result.size()-1]==ele && result[result.size()-2]==ele){
//insert a new character now
if(pq.empty()) break;
auto [newCurrCount,newEle]=pq.top();
pq.pop();
result+=newEle;
newCurrCount--;
if(newCurrCount>0) pq.push({newCurrCount, newEle});//push the new element and its count

pq.push({currCount,ele});//push the previous element and its count
        }else{
result+=ele;
currCount--;
if(currCount>0)
pq.push({currCount,ele});
        }
    }   
    return result;  
    }
};