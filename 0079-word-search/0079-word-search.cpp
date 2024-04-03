class Solution {
public:
bool isSafe(int row, int col, int n, int m,vector<vector<bool>>& visited,string word, int currindex, vector<vector<char>>&board ){
    return row>=0 && row<n && col>=0 && col<m && !visited[row][col] && board[row][col]==word[currindex];
}
bool wordExist(vector<vector<char>>&board, string word,int n, int m, vector<vector<bool>>& visited, int i, int j, int currindex){
// i -> row
// j -> col
  if(currindex>=word.length()) return true;
  
  if(!isSafe(i,j,n,m,visited,word,currindex,board)){
         return false;
    }

    visited[i][j]=true;
   bool wordFound =wordExist(board,word,n,m,visited,i,j+1,currindex+1) ||
                   wordExist(board,word,n,m,visited,i,j-1,currindex+1) || 
                   wordExist(board,word,n,m,visited,i+1,j,currindex+1) ||
                   wordExist(board,word,n,m,visited,i-1,j,currindex+1);
    visited[i][j]=false;
    return wordFound;
}

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==word[0] && wordExist(board,word, n, m, visited,i,j,0))
            return true;
        }
      }
      return false;
    }
};
// O(n*m*4^k)	The function wordExist is recursively called for each cell in the board, and at each call, it explores up to 4 neighboring cells. 'k' represents the length of the word being searched for