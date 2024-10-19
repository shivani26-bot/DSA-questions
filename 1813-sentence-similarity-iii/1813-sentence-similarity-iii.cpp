class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        
//         int n=sentence1.length();
//         int m=sentence2.length();
//         if(n<m) swap(sentence1,sentence2);
// // n>m then insert sentence in sentence2
// // n<m then insert sentence in sentence1
// deque<string>dq1,dq2;
// stringstream ss1(sentence1);
// stringstream ss2(sentence2);
// string s;
// while(ss1>>s){
//     dq1.push_back(s);
// }
// while(ss2>>s){
//     dq2.push_back(s);
// }
// while(!dq1.empty() && !dq2.empty() && dq1.front()==dq2.front()){
//     dq1.pop_front();
//     dq2.pop_front();
// }
// while(!dq1.empty() && !dq2.empty() && dq1.back()==dq2.back()){
//     dq1.pop_back();
//     dq2.pop_back();
// }
// return dq2.empty();

// two pointers 
  int n=sentence1.length();
        int m=sentence2.length();
        if(n<m) swap(sentence1,sentence2);
// n>m then insert sentence in sentence2
// n<m then insert sentence in sentence1
vector<string>v1,v2;
stringstream ss1(sentence1);
stringstream ss2(sentence2);
string s;
while(ss1>>s){
    v1.push_back(s);
}
while(ss2>>s){
    v2.push_back(s);
}
int i=0,j=v1.size()-1;
int k=0,l=v2.size()-1;
while(i<v1.size() && k<v2.size() && v1[i]==v2[k]){
    i++;
    k++;
}
while(j>=i && l>=k && v1[j]==v2[l]){
    j--;
    l--;
}
return l<k;
    }
};