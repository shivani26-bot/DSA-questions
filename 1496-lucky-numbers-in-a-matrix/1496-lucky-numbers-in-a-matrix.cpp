class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
// brute force 
// int n=matrix.size();
// int m=matrix[0].size();
// vector<int>result;
// // o((m*n)*(m+n))
// for every row check every column 
// for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
// int row=i,col=j;
// int rowMin=INT_MAX, colMax=INT_MIN;
//         for(int k=0;k<m;k++){
//           rowMin=min(rowMin,matrix[row][k]);
//         }
//         for(int k=0;k<n;k++){
//             colMax=max(colMax,matrix[k][col]);
//         }
//         if(rowMin==matrix[i][j] && colMax==matrix[i][j])
//         result.push_back(matrix[i][j]);
//     }
// }
// return result;

// int n=matrix.size();
// int m=matrix[0].size();
// vector<int>result;
// // o((m*n)*(m+n))
// // for every row check every column 
// for every cell find rowMin and colMax, then cehck whether the current element is roMin and colMax then that will be answer 
// for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){

// int rowMin=INT_MAX, colMax=INT_MIN;
//         for(int k=0;k<m;k++){
//           rowMin=min(rowMin,matrix[i][k]);
//         }
//         for(int k=0;k<n;k++){
//             colMax=max(colMax,matrix[k][j]);
//         }
//         if(rowMin==matrix[i][j] && colMax==matrix[i][j])
//         result.push_back(matrix[i][j]);
//     }
// }
// return result;


// for every row we need to maintain the row minimum and column minimum
// int n=matrix.size();
// int m=matrix[0].size();
// vector<int>result;
// vector<int>rowMin(n,INT_MAX);
// vector<int>colMax(m,INT_MIN);
// we can also use vector to store, minimum in each row and maximum in each column 
// for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//     rowMin[i]=min(rowMin[i],matrix[i][j]);
//     colMax[j]=max(colMax[j],matrix[i][j]);
//     }  
// }
   
//    again run for loop to check whether current cell is minimum in row and maximum in column 
// for(int i=0;i<n;i++){  
//     for(int j=0;j<m;j++){
//        if(rowMin[i]==matrix[i][j] && colMax[j]==matrix[i][j]){
//         result.push_back(matrix[i][j]);
//        }
//     }     
// }
// return result;

// int n=matrix.size();
// int m=matrix[0].size();
// vector<int>result;
// for(int i=0;i<n;i++){
//     int rowMin=INT_MAX;
//     int rowMinCol=-1;
//     for(int j=0;j<m;j++){
//         if(rowMin>matrix[i][j]){
//         rowMin=min(rowMin,matrix[i][j]);
//         rowMinCol=j;
//         }
//     }
// int colMax=INT_MIN;
// int colMaxRow=-1;
//     for(int k=0;k<n;k++){
//         if(colMax<matrix[k][rowMinCol]){
//        colMax=max(colMax, matrix[k][rowMinCol]);
// colMaxRow=k;
//         }
//     }
// //     if(i==colMaxRow) result.push_back(matrix[i][rowMinCol]);
// // }
// // return result;

// // or
//  if(i==colMaxRow) return {matrix[i][rowMinCol]};
// }
// return {};


int n=matrix.size();
int m=matrix[0].size();
// find minimum of each row and then find maximum out of all of them, because maximum elment will have more chances of being maximum in its column
// find maximum of each column and then find minimum out of all of them, because minimum element will have more changes of being minimum in its column

int rowMinMax=INT_MIN;
for(int row=0;row<n;row++){
    int rowMin=INT_MAX;
    for(int col=0;col<m;col++){
        rowMin= min(rowMin, matrix[row][col]);
    }
    rowMinMax=max(rowMinMax, rowMin);
}

int colMaxMin=INT_MAX;
for(int col=0;col<m;col++){

    int colMax=INT_MIN;
    for(int row=0;row<n;row++){
        colMax= max(colMax, matrix[row][col]);
    }
    colMaxMin=min(colMaxMin, colMax);
}

if(rowMinMax==colMaxMin)
return {rowMinMax};

return {};

// we can only have one lucky number in the matrix
// B X
// Y A
// for X to be a lucky number it should be X>A and X<B  ie A<X<B
// for Y to be lucky number it should be Y<A and Y>B ie B<Y<A which is not possible because from the above derivation A<B
    }
};

