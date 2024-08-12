class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    // start with direction east , and then go south, west and north
    // make a direction array
    // [[0,1][1,0][0,-1][-1,0]]
    //   e     s    w     n
    //   0     1    2     3

    //   keep a step variable, initially set to 1
    //   increase the step by one, when we change the direction from south to west
    //   increase the step by one, when we change the direction from north to east
    //   when we start we have the same steps number of steps in east and south, after that in west and north

//    finally the result size should be rows*cols 
//    keep a dir variable this will tell in which direction to move
// dir=0->east 1->south 2->west 3->north
// when we are at index 0 ie east or 2  ie west we should increase the step by 1
// every time we also increase the direction by 1 in order to change the direction after running required steps in 
// required directions
// dir=(dir+1)%4
// time complexity
// tc= o[max(row,col)]^2 ,because here it depends on the steps, not on rows*col
// when we will be in our last round then  steps that will be covered in all the direction will be max(rows, col)
vector<vector<int>>result;
vector<vector<int>>directions={{0,1},{1,0},{0,-1},{-1,0}};
int dir=0; //start from east direction
int steps=0;
result.push_back({rStart,cStart});
while(result.size() < rows*cols){
        if(dir==0 || dir==2) steps++;
        for(int count=0;count<steps;count++){
           rStart+=directions[dir][0];
           cStart+=directions[dir][1];
           if(rStart<rows && rStart>=0 && cStart>=0 && cStart<cols)
            result.push_back({rStart,cStart});
        }
        dir=(dir+1)%4;
        }
        return result;
    }
};