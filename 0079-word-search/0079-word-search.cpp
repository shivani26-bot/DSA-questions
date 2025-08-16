class Solution {
public:
int n, m;
bool isSafe(int i, int j, vector<vector<char>>& board,string word,vector<vector<bool>>& visited,int currIdx){
    // i -> row
// j -> col

    return i>=0 && i<n && j>=0 && j<m && !visited[i][j] && board[i][j]==word[currIdx];
}
bool solve(int i, int j, vector<vector<char>>& board,string word,vector<vector<bool>>& visited,int currIdx){

if(currIdx>=word.length()) return true;
if(!isSafe(i,j,board,word,visited,currIdx)) return false;
visited[i][j]=true;

bool wordFound= solve(i,j-1,board,word,visited, currIdx+1) || solve(i,j+1,board,word,visited, currIdx+1) ||solve(i-1,j,board,word,visited, currIdx+1) ||solve(i+1,j,board,word, visited,currIdx+1);
visited[i][j]=false;

    return wordFound;
}
    bool exist(vector<vector<char>>& board, string word) {
       n=board.size();
       m=board[0].size();
      vector<vector<bool>>visited(n,vector<bool>(m,false));
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(word[0]==board[i][j] && solve(i,j,board,word,visited,0)){
                return true;
            }
        }
       }
       return false; 
    }
};

// O(n*m*4^k)	The function wordExist is recursively called for each cell in the board, and at each call, it explores up to 4 neighboring cells. 'k' represents the length of the word being searched for