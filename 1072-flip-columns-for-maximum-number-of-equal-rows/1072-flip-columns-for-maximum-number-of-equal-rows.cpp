class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    //  exactly same rows
    //  1 0 1
    //  1 0 1
    //  0 0 1 if we flip second column, then first two rows will be same as both the rows are same initially
    //  after flip 
    //  1 1 1
    //  1 1 1
    //  0 1 1 
    // exactly inverted rows
    // 1 0 1
    // 0 1 0
    // 0 0 1 first two rows are inverted, hence if we flip second column first rows will have same numbers in it
    // after flip
    // 1 1 1
    // 0 0 0
    // 0 0 1
// 0 0 0
// 0 0 1
// 1 1 0
// we have inverted row for second row 0 0 1, hence two rows can be made such that numbers in both the rows are equal
// for every row we try to find rows which are either similar to it or rows which are inverted to it

// pick each row
// same rows and inverted rows for each row
// 1 1 0 1
// 0 0 1 1
// 1 1 0 1
// 1 1 0 1
// 0 0 1 0
// flip column 3rd we have row 1st,3rd,4th,5th which have same numbers in it
// after flip:
// 1 1 1 1
// 0 0 0 1
// 1 1 1 1
// 1 1 1 1
// 0 0 0 0
// int m=matrix.size();
// int n=matrix[0].size();

// int maxRow=0;
// // time: o(m *(n+ m*n))
// for(auto& currRow: matrix){//o(m)
//     vector<int>inverted(n);
//     for(int col=0;col<n;col++){//o(n)
//         inverted[col]=currRow[col]==0 ? 1 :0;
//     }
//     int count=0;
//     for(auto &row:matrix){//o(m)
//         if(row==currRow || row ==inverted){ //o(n)
//                  count++;
//         }
//     }
//     maxRow=max(maxRow,count);
// }
// return maxRow;

// 2nd approach 
// nature for such rows ie similar or inverted will be similar

// 0 0 1 0 0 1 s s b s s b where s->same, b->badla
// 1 1 0 1 1 0 s s b s s b
// 0 1 0 1 0 1 s b s b s b
// ex: 0 0 0 s s s
//     0 0 1 s s b
//     1 1 0 s s b
//     map:
//     sss->1
//     ssb->2
// time: o(m*n)
 int m=matrix.size();
 int n=matrix[0].size();
 unordered_map<string,int>mp;
 for(auto &row: matrix){
    string rowKaNature="";
    int firstVal=row[0];
    for(int col=0;col<n;col++){
        rowKaNature+= (row[col]==firstVal ? "S":"B");
    }
    mp[rowKaNature]++;
 }
 int maxRows=0;
 for(auto &it: mp){
    maxRows=max(maxRows,it.second);
 }
 return maxRows;

    }
};