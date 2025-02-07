/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* ht;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public: 
bool isSame(int x, int y, int n, vector<vector<int>>&grid){
    int ele=grid[x][y];
    for(int i=x;i<x+n;i++){
        for(int j=y;j<y+n;j++){
            if(grid[i][j]!=ele) return false;
        }
    }
    return true;
}
Node* solve(int x, int y, int n,vector<vector<int>>& grid ){
    if(isSame(x,y,n,grid)){
return new Node(grid[x][y],true);
    }
    else{
Node * root= new Node(1, false);
root->topLeft=solve(x,y,n/2,grid);
root->topRight=solve(x,y+n/2,n/2,grid);
root->bottomLeft=solve(x+n/2, y,n/2,grid);
root->bottomRight=solve(x+n/2, y+n/2,n/2 ,grid);
return root;
    }
}
    Node* construct(vector<vector<int>>& grid) {
        // convert grid to quad tree
        // a node has value, isLeaf or not, and 4 pointers pointing to its 4 children 
// divide the grid in 4 parts, top left, top right, bottom left, bottom right
// after dividing the grid if all the values are same in the subgrid then set isLeaf True, and set val to value of grid and set 4 children to null and stop 
// if subgrid has different values, set isLeaf to false and set val to any value and divide the current grid into 4 sub grids, recurse for each children
// start from 0,0, check in entire grid that all the values are same in it or not
// if not same then divide the grid into subgrid, root will be the entire matrix initally value set to either 0 or 1 and is leaf is false, it has 4 pointers topleft, topright, bottomright, bottomleft
// start with the entire grid , size=n
 int n=grid.size();
 return solve(0,0,n,grid);
    }
};