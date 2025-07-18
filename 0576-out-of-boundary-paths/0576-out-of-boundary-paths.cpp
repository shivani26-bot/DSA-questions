class Solution {
public:
// recursion
// # define mod 1e9+7

// bool isSafe(int m,int n, int startRow, int startColumn){
//     if(startRow<0|| startColumn<0 || startColumn>=m|| startRow>=n  ) return false;
//     return true;
// }

// long long solve(int n, int m, int maxMove, int startRow,  int startColumn){
//     if(maxMove==0){
//         if(isSafe(m,n,startRow,startColumn)) return 0;
//         return 1;
//     }

//     if(!isSafe(m,n,startRow,startColumn)) return 1;


//     long long l  =   solve(n,m,maxMove-1,startRow,startColumn-1); 
//     long long r  =    solve(n,m,maxMove-1,startRow,startColumn+1);
//     long long u  =   solve(n,m,maxMove-1,startRow-1,startColumn);  
//     long long d  =   solve(n,m,maxMove-1,startRow+1,startColumn);
//     long long t=(l+r+u+d)%(long long)(mod);
//     return t;

// }
//     int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
// long long ans= solve(m,n,maxMove, startRow, startColumn) % (long long)(mod);
// return  ans;
//     }

# define mod 1e9+7

bool isSafe(int m,int n, int startRow, int startColumn){
    if(startRow<0|| startRow>=n|| startColumn<0 || startColumn>=m  ) return false;
    return true;
}

long long solve(int n, int m, int maxMove, int startRow,  int startColumn,vector<vector<vector<long long>>>&dp){
    if(maxMove==0){
        if(isSafe(m,n,startRow,startColumn)) return 0;
        return 1;
    }

    if(!isSafe(m,n,startRow,startColumn)) return 1;
if(dp[startRow][startColumn][maxMove] != -1) return dp[startRow][startColumn][maxMove];

    long long r  =    solve(n,m,maxMove-1,startRow,startColumn+1,dp);
    long long l  =    solve(n,m,maxMove-1,startRow,startColumn-1,dp);
    long long d  =   solve(n,m,maxMove-1,startRow+1,startColumn,dp);  
    long long u  =   solve(n,m,maxMove-1,startRow-1,startColumn,dp);
    long long count=(l+r+u+d)%(long long)(mod);
    return dp[startRow][startColumn][maxMove]=count;

}
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
 vector<vector<vector<long long>>>dp(m,vector<vector<long long>>(n,vector<long long>(maxMove+1,-1)));
long long ans= solve(m,n,maxMove, startRow, startColumn,dp) % (long long)(mod);
return  ans;
    }
};