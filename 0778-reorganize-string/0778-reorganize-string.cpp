class Solution {
public:
// aaabbbcdd
// "vvvlo"
//"aaa" 
    string reorganizeString(string s) {
        //   the character whose frequency is higher that causes problem here, as we don't want them to be together
        // if any character occurs more than ceil value of (n+1)/2 it means we can't arrange the string
        // if there is only 1 type of letter in string pq will have size 1 we can't form a string
    //     int n=s.length();
    //   unordered_map<char,int>mp;
    //   for(auto &ch:s){
    //    mp[ch]++;
    //   }
    


    // priority_queue<pair<int,char>>pq;//will store frequency and character

    // for(auto &it:mp){
    //            if(it.second>ceil((n+1)/2)) return "";

    //     pq.push({it.second, it.first});
    // }
    // // if(pq.top().first>ceil((n+1)/2)) return "";
    // string result;
    // while(pq.size()>=2){
    //     // pop two elements at once it will help to avoid the case when same letter comes on top of the heap 
    //     auto [count,ele]=pq.top();
    //     pq.pop();
    //     auto [count1,ele1]=pq.top();
    //     pq.pop();
        
    //     result+=ele;
    //     result+=ele1;
    //     count--;
    //     count1--;
    //     if(count>0)
    //     pq.push({count,ele});
    //     if(count1>0){
    //         pq.push({count1,ele1});
    //     }
    // }
    // if(!pq.empty()){
    //     result+=pq.top().second;
    // }
    // return result;




    //another approach: greedy 
// take a result of size n, start from index=0, and fill the character with highest frequency first, fill them at interval of 1, i=0,2,4,6 once i will be out of bound
// start from i=1,3,5,7
//odd even placement

    int n=s.length();
vector<int>count(26,0);

int maxFreq=0;
char maxFreqChar;
for(char&ch: s){
    count[ch-'a']++;
    if(count[ch-'a']>maxFreq){
        maxFreq=count[ch-'a'];
        maxFreqChar=ch;
    }
    if(count[ch-'a']>(n+1)/2) return "";

}
     
     int idx=0;
     string result=s;
    //  place most frequent char
     while(count[maxFreqChar-'a']!=0){
        result[idx]=maxFreqChar;
        idx+=2;
        count[maxFreqChar-'a']--;
     }
     //place rest letter in any order;
     for(char ch='a';ch<='z';ch++){

while(count[ch-'a']>0){
    if(idx>=n){
        idx=1;
    }
            result[idx]=ch;
            idx+=2;
        count[ch-'a']--;

}


     }
     return result;
    }
};