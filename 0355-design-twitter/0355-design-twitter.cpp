class Twitter {
public:
    Twitter() {
        
    }
    int time=0;//global time
   
    unordered_map<int,unordered_set<int>>followersList;
    unordered_map<int,vector<pair<int,int>>>postsList;//for each userId-> {time,postId}

    void postTweet(int userId, int tweetId) {
        postsList[userId].push_back({time++,tweetId});
    }
    
   
    vector<int> getNewsFeed(int userId) {
 priority_queue<pair<int,int>>pq;//{time,userid} who has done recent post
    // map<int,vector<int>>followersList; //we can also use set instead of vector<int>

    // vector<pair<int,int>>&posts= postsList[userId];
// for(auto it=posts.begin();it!=posts.end();it++){
//   pq.push({it.first,it.second});  
// }
for(auto tweet:postsList[userId]){//we get pair of {time, postId}
    pq.push(tweet);//{time,userId}
}

//now find post posted by all the users who are followed by userId
for(int followeeId: followersList[userId]){
        for(auto tweet: postsList[followeeId]){
            pq.push(tweet); //{time,userId}
        }
}
//extract at most 10 tweets
int count=0;
vector<int>result; //show the element which will appear in feed of userId
while(!pq.empty() && count<10){
      result.push_back(pq.top().second);
      pq.pop();
      count++;
}
return result;

    }
    
    void follow(int followerId, int followeeId) {
        // if(followerId==followeeId) return ;//not necessary
        // followersList[followerId].push_back(followeeId);
        followersList[followerId].insert(followeeId);//set
    }
    
    void unfollow(int followerId, int followeeId) {
        // vector<int>&followee= followersList[followerId]; //use reference to modify original vector, vector<int>followee will only create a copy 
        // for(auto it=followee.begin() ;it!=followee.end();it++){
        //     if(*it==followeeId){
        //         followee.erase(it);//erase expects the iterator
        //         break;
        //     }
        // }

        followersList[followerId].erase(followeeId); //set
  
        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */