class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
    //  int time=0;   
    // int i=0;
    // while(tickets[k]!=0){
    //     if(i==tickets.size()){
    //         i=0;
    //     }
    //     if(tickets[i]==0) {
    //         i++;
    //         continue;
    //     }
    //     tickets[i]--;
    //     time++;
    //     i++;
    // }
    //  return time;
    // with queue 
    // time: n* maxTickets[i]
    // space: o(n)
    // int time =0;
    // queue<int>q;
    // for(int i=0;i<tickets.size();i++) q.push(i);
    // while(!q.empty()){
    //     time++;
    //     int frontEle = q.front();
    //     q.pop();
    //     tickets[frontEle]--;

    //     if(tickets[frontEle]!=0) q.push(frontEle);
    //     if(frontEle == k && tickets[frontEle]==0) return time;
    // }
    // return time;

    int time=0;
    for(int i=0;i<tickets.size();i++){
        if(i<=k) time+= min(tickets[k],tickets[i]);
        else time+= min(tickets[k]-1, tickets[i]);
    }
    return time;
    }
};