class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        int n=sentence1.length();
        int m=sentence2.length();
        if(n<m) swap(sentence1, sentence2);
       deque<string>dq1,dq2;
       stringstream ss1(sentence1);
       stringstream ss2(sentence2);
       string s;
       while(ss1>>s){
        dq1.push_back(s);
       }
       while(ss2>>s){
        dq2.push_back(s);
       }
       while(!dq1.empty() && !dq2.empty() && dq1.front()==dq2.front()){
        dq1.pop_front();
        dq2.pop_front();
       }
         while(!dq1.empty() && !dq2.empty() && dq1.back()==dq2.back()){
        dq1.pop_back();
        dq2.pop_back();
       }
       return dq2.empty();

        
    }
};