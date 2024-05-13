class Solution {
public:

// try to find the contribution of each cell , each row in first column
// must be 1 for high score
// contribution of cell grid[0][0] = grid[0][0]*2^m-1-j j=0
// contribution of cell grid[0][1] = grid[0][1]*2^m-1-j j=1
// for n rows, contribution of each row in first column n*2^(m-1-j) j=0
//  column 1 must have all 1's if its not then flip the entire row
    int matrixScore(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();



       for(int i=0;i<n;i++){
          if(grid[i][0]==1)  continue;
        for(int j=0;j<m;j++){
           grid[i][j]=!grid[i][j];
        //    or use xor to flip
        //    grid[i][j]^=1
        }
       } 

    //      for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //        cout<< grid[i][j]<<" ";
    //     }
    //     cout<<endl;
    //    } 

// now modify the column based on number of count of 1 present in it
// n-countOf1's>1 then flip that column as we want max number of 1's in a column
// n-countOf1's gives countOf0's
// and contribution column wise will be (n-countOf1's)*2^(n-1-j)
        for(int j=1;j<m;j++){
            int colCount1s=0;
           
        for(int i=0;i<n;i++)
           colCount1s+=grid[i][j];
          
           int colCount0s= n-colCount1s;
           if(colCount1s < colCount0s )  {
            //flip
            for(int i=0;i<n;i++)
            grid[i][j]^=1;

           }
                
    
        }
       

       
//  cout<<endl;
//          for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//            cout<< grid[i][j]<<" ";
//         }
//         cout<<endl;
//        } 
        int sum = 0;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        // sum+= grid[i][j]* pow(2,m-1-j);
        sum+= grid[i][j]* (1<<(m-1-j));
    }
}
    return sum;
    }
};