class Solution {
public:
int dp[1001][1001];
// int solve(vector<vector<int>>& books,int currIndex, int remainW, int maxHeight,int n,int shelfWidth){
//     if(currIndex>=n) return maxHeight;
//     int bookWidth= books[currIndex][0];
//     int bookHeight= books[currIndex][1];

//     int keep=INT_MAX;
//     int skip=INT_MAX;
//     if(bookWidth<=remainW){
//         keep=solve(books,currIndex+1,remainW-bookWidth,max(maxHeight,bookHeight),n,shelfWidth);
//     }
//    skip=maxHeight+solve(books,currIndex+1,shelfWidth-bookWidth,bookHeight,n,shelfWidth);
// return min(keep,skip);
// }
//     int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
//     //    for every book we have 2 options, that we can keep it in current shelf or we can't keep it in current shelf  
//     // if we keep , we will keep the book on the same shelf
//     // if we skip it means that we will now keep the book on next shelf
//     // if we continue to keep the book on same shelf we maintain a maxHeight , which keep the track
//     // of maximum height of book in the current shelf
//     // if we skip then we add the maxHeight till the previous shelf and now the height will be the height
//     // of current book, as we are placing it for first time in new shelf 
//     // return minimum of keep and skip 
//     // base case will be once we reach the end of array return maxHeight 
//       int n=books.size();
//       int remainW=shelfWidth;
// // remaining width, current index, maximum height
//       return solve(books, 0, remainW,0,n,shelfWidth);
//     }

int solve(vector<vector<int>>& books,int currIndex, int remainW, int maxHeight,int n,int shelfWidth){
    if(currIndex>=n) return maxHeight;
    if(dp[currIndex][remainW]!=-1) return dp[currIndex][remainW];
    int bookWidth= books[currIndex][0];
    int bookHeight= books[currIndex][1];

    int keep=INT_MAX;
    int skip=INT_MAX;
    if(bookWidth<=remainW){
        keep=solve(books,currIndex+1,remainW-bookWidth,max(maxHeight,bookHeight),n,shelfWidth);
    }
   skip=maxHeight+solve(books,currIndex+1,shelfWidth-bookWidth,bookHeight,n,shelfWidth);
return dp[currIndex][remainW] =min(keep,skip);
}
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
memset(dp,-1,sizeof(dp));
      int n=books.size();
      int remainW=shelfWidth;
// remaining width, current index, maximum height
      return solve(books, 0, remainW,0,n,shelfWidth);
    }
};