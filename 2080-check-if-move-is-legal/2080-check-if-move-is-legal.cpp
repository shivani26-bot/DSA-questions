class Solution {
public:

// bool isSafe(int i, int j){
//     return i>=0 && j>=0 && i<8 && j<8;
// }
// bool left(int i, int j,vector<vector<char>>& board,char initialColor ){
//    j--;
//     if(!isSafe(i,j) || board[i][j]=='.' || board[i][j]==initialColor) return false;
//   while(isSafe(i,j)){
//         char currColor=board[i][j];
        
//     if( currColor=='.') return false;
// if( currColor==initialColor) return true;
// j--;
//     }
//     return false;
// }
// bool right(int i, int j,vector<vector<char>>& board,char initialColor ){
//    j++;
//     if(!isSafe(i,j) || board[i][j]=='.' || board[i][j]==initialColor) return false;
//   while(isSafe(i,j)){
//         char currColor=board[i][j];
        
//       if( currColor=='.') return false;
// if( currColor==initialColor) return true;
// j++;
//     }
//     return false;
// }

// bool up(int i, int j,vector<vector<char>>& board,char initialColor ){
//    i--;
//     if(!isSafe(i,j) || board[i][j]=='.' || board[i][j]==initialColor) return false;
//   while(isSafe(i,j)){
//         char currColor=board[i][j];
        
//     if( currColor=='.') return false;
// if( currColor==initialColor) return true;
// i--;
//     }
//     return false;
// }
// bool down(int i, int j,vector<vector<char>>& board,char initialColor ){
//    i++;
//     if(!isSafe(i,j) || board[i][j]=='.' || board[i][j]==initialColor) return false;
//   while(isSafe(i,j)){
//         char currColor=board[i][j];
        
//      if( currColor=='.') return false;
// if( currColor==initialColor) return true;
// i++;
//     }
//     return false;
// }
// bool topRight(int i, int j,vector<vector<char>>& board,char initialColor ){
//    i--;j++;
//     if(!isSafe(i,j) || board[i][j]=='.' || board[i][j]==initialColor) return false;
//   while(isSafe(i,j)){
//         char currColor=board[i][j];
        
//     if( currColor=='.') return false;
// if( currColor==initialColor) return true;
//  i--;j++;
//     }
//     return false;
// }
// bool topLeft(int i, int j,vector<vector<char>>& board,char initialColor ){
//    i--;j--;
//     if(!isSafe(i,j) || board[i][j]=='.' || board[i][j]==initialColor) return false;
//   while(isSafe(i,j)){
//         char currColor=board[i][j];
//         if( currColor=='.') return false;
// if( currColor==initialColor) return true;
//    i--;j--;
//     }
//     return false;
// }

// bool bottomRight(int i, int j,vector<vector<char>>& board,char initialColor ){
//    i++;j++;
//     if(!isSafe(i,j) || board[i][j]=='.' || board[i][j]==initialColor) return false;
//   while(isSafe(i,j)){
//         char currColor=board[i][j];
//  if( currColor=='.') return false;
// if( currColor==initialColor) return true;
//  i++;j++;
//     }
//     return false;
// }

// bool bottomLeft(int i, int j,vector<vector<char>>& board,char initialColor ){
//    i++;j--;
//     if(!isSafe(i,j) || board[i][j]=='.' || board[i][j]==initialColor) return false;
//   while(isSafe(i,j)){
//         char currColor=board[i][j];
//  if( currColor=='.') return false;
// if( currColor==initialColor) return true;

//    i++;j--;
//     }
//     return false;  
// }
//     bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
// if(board[rMove][cMove]!='.') return false;

// return right(rMove,cMove, board,color)||left(rMove,cMove, board,color)||up(rMove,cMove, board,color)||down(rMove,cMove, board,color)||topRight(rMove,cMove, board,color)||topLeft(rMove,cMove, board,color)||bottomRight(rMove,cMove, board,color)||bottomLeft(rMove,cMove, board,color);



//     }

 bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
char oppColor= color=='B' ? 'W':'B';

int xdir[8]={1,1,0,-1,-1,-1,0,1};
int ydir[8]={0,-1,-1,-1,0,1,1,1};
for(int k=0;k<8;k++){
    int x=rMove+xdir[k];
    int y=cMove+ydir[k];
    bool seenOpp=false, flag=false;
    for(;x>=0 && y>=0 && y<8 && x<8 ;x+=xdir[k],y+=ydir[k]){
        if(board[x][y]=='.') break;
        else if(board[x][y]!=oppColor){
            flag=true;
            break;
        }
        else if(!seenOpp) seenOpp=true;
    }
    if(seenOpp && flag) return true; //i you have seen opposite color as well seen the same color at endpoint return true;
}
return false;
    }
};