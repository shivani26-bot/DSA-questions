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

int n=matrix.size();
int m=matrix[0].size();
vector<int>result;
// o((m*n)*(m+n))
// for every row check every column 
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){

int rowMin=INT_MAX, colMax=INT_MIN;
        for(int k=0;k<m;k++){
          rowMin=min(rowMin,matrix[i][k]);
        }
        for(int k=0;k<n;k++){
            colMax=max(colMax,matrix[k][j]);
        }
        if(rowMin==matrix[i][j] && colMax==matrix[i][j])
        result.push_back(matrix[i][j]);
    }
}
return result;


// for every row we need to maintain the row minimum and column minimum
// int n=matrix.size();
// int m=matrix[0].size();
// vector<int>result;
// vector<int>rowMin(n,INT_MAX);
// vector<int>colMax(m,INT_MIN);
// for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//     rowMin[i]=min(rowMin[i],matrix[i][j]);
//     colMax[j]=max(colMax[j],matrix[i][j]);
//     }  
// }
   
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

// we can only have one lucky number in the matrix
// B X
// Y A
// for X to be a lucky number it should be X>A and X<B  ie A<X<B
// for Y to be lucky number it should be Y<A and Y>B ie B<Y<A which is not possible because from the above derivation A<B
    }
};