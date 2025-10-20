class Solution {
public:
bool isMagicGrid(vector<vector<int>>&grid, int r, int c){

// elements from 1 to 9 and must be unique 
unordered_set<int>st;

    for(int k=r;k<r+3;k++){
        for(int l=c;l<c+3;l++){
            if(grid[k][l]<1 || grid[k][l]>9|| st.count(grid[k][l]))                return false;
            else st.insert(grid[k][l]);
        }
    }
    int rowSum=grid[r][c]+grid[r][c+1]+grid[r][c+2];
    for(int i=0;i<3;i++){
        if(grid[r+i][c]+grid[r+i][c+1]+grid[r+i][c+2] != rowSum)
            return  false;
        if(grid[r][c+i]+grid[r+1][c+i]+grid[r+2][c+i] != rowSum)
            return  false;

           

    }
     // diagonal elements always follow the following order
// r,c => r+1,c+1=>r+2,c+2 and so on 
if(grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2]!=rowSum) return false;

// anti diagonal elements always follow the following order
// if given r,c, start from r+3-1, c+3-1 ie r=r+2,c=c+2 and other antidiagonal coordinates will be, r-1,c+1

if(grid[r][c+2]+grid[r+1][c+2-1]+grid[r+2][c+2-2]!=rowSum) return false;

    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //        int num= grid[r+i][c+i];
    //         if(num<1 || num>9|| st.count(num))                return false;
    //         else st.insert(num);
    //     }
    // }
    return true;
}
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        // if we want to form a 3*3 grid , then we can start from 0th column and go till column= grid column size - 3
        // then we can start from 0th row and go till row= grid row size - 3
        // rows=3
        // cols=4
        // in column we can go from col =0 to 4-3=1
        // in row we can go from row=0 to 3-3=0
        int countMagicGrid=0;
int rows=grid.size();
int cols=grid[0].size();
        for(int i=0;i<=rows-3;i++){
            for(int j=0;j<=cols-3;j++){
                if(isMagicGrid(grid,i,j))
                countMagicGrid++;
            }
        }
        return countMagicGrid;
    }
};