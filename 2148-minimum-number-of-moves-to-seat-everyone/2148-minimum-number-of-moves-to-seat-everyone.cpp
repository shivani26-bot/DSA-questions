class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        // 2 students can't occupy the same seat but they can occupy the seat at the same location 
        // seat[i] is the location of ith seat
        // student[i] is the location of ith student
//         seats = [3,1,5], students = [2,7,4]
// 0th student at location 2 and 0th seat at location 2 
//  1th student at location 7 and 1th seat at location 1
//   2th student at location 4 and 2th seat at location 5
//   it's possible that multiple seats at same location 
//   seats = [2,2,6,6]
//   2 seats at location 2 as well as location 6
// student nearer to the seat will occupy that seat 
sort(seats.begin(),seats.end());
sort(students.begin(),students.end());
int ans=0;
for(int i=0;i<seats.size();i++){
    if(seats[i]!=students[i]){
    ans+=abs(seats[i]-students[i]);
    }
}
return ans;
    }
};