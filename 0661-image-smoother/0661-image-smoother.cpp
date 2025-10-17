class Solution {
public:
//define directions for each neighbors
vector<vector<int>>directions{
    {-1,-1},{-1,0},{-1,1},
    {0,-1},{0,0},{0,1},
    {1,-1},{1,0},{1,1}
};
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    //     filter need to be applied to each cell, filter is of 3x3 size
    //  average=(sum of current cell and surrounding neighbors)/total_cells ie(current+surrounding)
    //  for corner elements divide by 4, 
    // for a given cell we need top right/left, bottom right/left, vertical and horizontal neighbors
    // for i, j => surrounding neighbors: (i-1,j-1),(i-1,j+1),(i+1,j-1),(i+1,j+1),(i-1,j),(i+1,j),(i,j-1),(i,j+1)
// also neighboring cells should be valid and not out of bound 
// use a separte matrix as we will modify the current cell value with average value 
// int m=img.size();
// int n=img[0].size();
// vector<vector<int>>result(m,vector<int>(n,0));
// for(int i=0;i<m;i++){
//     for(int j=0;j<n;j++){
        
//         int sum_nghbrs=0;
//         int count_nghbrs=0;

//         for(auto &it:directions){
//             int i_=i+it[0];
//             int j_=j+it[1];

//             if(i_>=0 && i_<m && j_>=0 && j_<n){
//                 // valid coordinate 
//                 sum_nghbrs+=img[i_][j_];
//                 count_nghbrs++;
//             }
//         }
//         result[i][j]=sum_nghbrs/count_nghbrs;
//     }
// }
// return result;

// optimize space 
// for a given row we need just previous row 
// maintain a vector which will store the previous row's original value 
// use a extra variable to store top corner value, 
// for every i, j add the bottom/right neighbors which is also called as  the future cells which are not yet processed, 
// find the top negihbors for the curent cell using previous row array , for top corner use top corner variable and left neighbor also obtained from previous row 



// before updating the value in matrix update in previous row array for that column
// for ex: if updating value for [0][1] in matrix update for index 1 in previous row array
// while moving to next cell, to get the left cell value use previous index for (j in matrix ) in previous row array
// for ex: for [0][1], left cell value is present at previous_row[0],
// before updating the value of previous row array, store the value present in the previous row cell to top corner variable  because updated value will act as left column value for next cell in matrix and top corner variable act as topcorner element for next cell in matrix

int m=img.size();
int n=img[0].size();

vector<int>prev_row(n);
int prevCorner=0;

// traverse through each cell 
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
int sum=0;
int count=0;

// first add the bottom neighbors
if(i+1<m){
    if(j-1>=0){
        sum+=img[i+1][j-1]; //bottom left corner
        count++;
    }
    sum+=img[i+1][j]; // bottom vertical
    count++;
    if(j+1<n){
        //bottom right corner
        sum+=img[i+1][j+1];
        count++;
    }
}

  // just right nghbr 
    if(j+1<n){
        sum+=img[i][j+1];
        count++;
    }

//just left neighbor [i][j-1]
if(j-1>=0){
         sum+=prev_row[j-1];
        count++;
}
 // current cell 
    sum+=img[i][j];
    count++;

    // top neigbors 
    if(i-1>=0){
        // prevcorner [i-1][j-1]
        if(j-1>=0){
            sum+=prevCorner; //top left corner
            count++;
        }

        sum+=prev_row[j]; //top vertical
        count++;

        if(j+1<n){
            sum+=prev_row[j+1]; //top right corner
            count++;
        }
    }

// store prev value of prev_row 
if(i-1>=0)
    prevCorner=prev_row[j]; //before updating prev_row[j] just store it's value as prevCorner as it be used by next row in matrix
    // store current value of [i][j]
    prev_row[j]=img[i][j];
// now update the img[i][j] vlaue with the avg value
img[i][j]=sum/count;


    }

}
return img;
    }
};