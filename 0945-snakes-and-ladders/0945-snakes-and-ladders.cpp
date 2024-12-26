class Solution {
public:

pair<int,int> getCoord(int num, int n){
    int rt=(num-1)/n; // row from top
    int rb= (n-1)- rt;//row from bottom
    int col= (num-1)%n;
    // for right to left 
    // (n-1) - ((val-1)%n)
    if((n%2==1 && rb%2==1) || (n%2==0 && rb%2==0))
     col=n-1-col;

     return make_pair(rb,col);

}
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        // at any given cell x we have 6 options , we can go to x+1,x+2,x+3,x+4,x+5,x+6 by rolling a dice
//         1
// 2     3          4  5  6  7
//     4 5 6 7 8 9
//     we can reach 4,5,6,7 in one step from 1 hence we will mark it visited because from 3 it takes two step to go to 4,5,6,7
//     in question minimum steps is asked hence think of bfs
//     maintain a visited array of n*n matrix, mark false initially
//     start from board[n-1][0]
//     mark visited[n-1][0]=true
//     queue:
//     1
//     2 3 4 5 6 7 pop 1
//     3 4 5 6 7 15 pop 2
//     4 5 6 7 15 8 pop 3
//     push elements in queue and mark corresponding cell visited as true;
//    Time Complexity : Since in worst case, we will visit all the cells and there are n^2 cells, so time complexity will be O(n^2)

// Space Complexity : We took visited array of size n^2 and also in worst case, our queue will have n^2 elements. So Space Complexity will be O(n^2)
   
    queue<int>q;
    q.push(1);
    int steps=0;
    vector<vector<bool>>visited(n,vector<bool>(n,false));
    visited[n-1][0]=true;
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
        int x=q.front();
        q.pop();
        if(x==n*n) return steps;
        for(int i=1;i<=6;i++){
            int adjx= x+i;
            if(adjx>n*n) break;
           pair<int,int>coord=getCoord(adjx,n);
           int r=coord.first;
           int c=coord.second;
           if(visited[r][c]) continue;
           visited[r][c]=true;
        //    if(board[r][c]==-1){
        //     q.push(adjx);
            
        //    } 
        //    else{ //if board[r][c]!=-1
        //     q.push(board[r][c]);
        //    } 
        if(board[r][c]!=-1){
              q.push(board[r][c]);
           } 
           else{ //if board[r][c]==-1
            q.push(adjx);
           } 
        }
            }
         steps++;
    
    }
    return -1; //if x==n*n condition is not met in the entire for loop
    }
};

// how to find a (r,c) for a given value in matrix, value must be sequential
//   0 1 2
// 0 1 2 3
// 1 4 5 6 
// 2 7 8 9
// in order to find row for value 6
// (6-1)/n= (6-1)/3=5/3=1, 6-1 because indexing starts from 0
// (5-1)/3=1
// (4-1)/3=1
// (8-1)/3=2
// row_from_top=(num-1)/n
// row_from_bottom=(n-1) - row_from_top // n-1 because indexing is 0 based

// in order to find col for value 6
// (6-1)%n=(6-1)%3=2
// (8-1)%3=1

// here numbering is done from left to right in one row and right to left
// in another row, in alternate fashion
// for left to right , column = (val-1)%n
// for right to left, column= (n-1) - ((val-1)%n) //n-1 because indexing is 0 based


//    0   1    2   3  4   5
// 0  36  35  34  33  32 31

// 1  25  26  27  28  29 30

// 2  24  23  22  21  20 19

// 3  13  14  15  16  17 18

// 4  12  11  10  9   8  7

// 5  1   2   3   4   5  6
// when n is even
// n=6 row_bottom=5
// n=6 row_bottom=4
// n=6 row_bottom=3
// n=6 row_bottom=2
// if both n and row_bottom are even it means right to left
// if both n and row_bottom are even and odd it means left to right

// if n is odd and row bottom is also odd then it will be right to left;
// if n is odd and row bottom is even then it will be left to right;

