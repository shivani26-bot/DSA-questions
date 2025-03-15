class NumArray {
public:
int n;
vector<int>segmentTree;
void buildSegmentTree(int idx, int l, int r , vector<int>&nums)
    {
        if(l==r){
            segmentTree[idx]=nums[l];
            return;
        }
        int mid=l+(r-l)/2;
        buildSegmentTree(2*idx+1, l, mid, nums);//left tree
        buildSegmentTree(2*idx+2,mid+1, r, nums); //right tree
        segmentTree[idx]=segmentTree[2*idx+1]+segmentTree[2*idx+2];//root


    }
        
        
        NumArray(vector<int>& nums) {
       n=nums.size();
       segmentTree.resize(4*n);
       buildSegmentTree(0,0,n-1, nums); 
    }
    void updateSegmentTree(int index, int val,int i, int l, int r )
   {
if(l==r){
    segmentTree[i]=val;
    return;
}
int mid=l+(r-l)/2;
if(index<=mid){
    updateSegmentTree(index,val,2*i+1,l,mid);
}
else{
    updateSegmentTree(index,val,2*i+2,mid+1,r);
}
segmentTree[i]=segmentTree[2*i+1]+segmentTree[2*i+2];
   }
   
    void update(int index, int val) {
        updateSegmentTree(index,val,0,0,n-1);//point update in a segment tree
    }
    
    int querySegmentTree(int start, int end, int i, int l, int r){
        if(l>end || r<start) return 0; //out of range
        if(l>=start && r<=end) {
            return segmentTree[i];
        }
        int mid=l+(r-l)/2;
        return querySegmentTree(start,end, 2*i+1,l, mid)+querySegmentTree(start,end, 2*i+2,mid+1,r);
        
    }
    int sumRange(int left, int right) {
        return querySegmentTree(left,right,0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */