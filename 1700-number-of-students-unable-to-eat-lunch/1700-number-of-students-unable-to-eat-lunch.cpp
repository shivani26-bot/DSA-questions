class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
//         queue<int>stdnts;
//         stack<int>sndwchs;
//         int n=sandwiches.size();
//         for(int i=n-1; i>=0; i--){
//             sndwchs.push(sandwiches[i]);
//         }
//         for(int i=0;i<n;i++){
//             stdnts.push(students[i]);
//         }
//         int served=0;
// while(!stdnts.empty() && served < stdnts.size()){
         
//         if(stdnts.front()==sndwchs.top()){
//             stdnts.pop();
//             sndwchs.pop();
//             served=0;
//         }
//         else{
//             stdnts.push(stdnts.front());
//              stdnts.pop();
//              served++;
//         }
// }
// return stdnts.size();

int squareStudentCount=0, circleStudentCount=0;
for(int i=0;i<students.size();i++){
    if(students[i]==0) circleStudentCount++;
    else squareStudentCount++;
}
for(int i=0;i<sandwiches.size();i++){
    if(sandwiches[i]==1){
        if(squareStudentCount>0) squareStudentCount--;
        else break;
    }
    if(sandwiches[i]==0){
        if(circleStudentCount>0) circleStudentCount--;
        else break;
    }
}
return squareStudentCount+circleStudentCount;
    }
};