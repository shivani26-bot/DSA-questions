class Solution {
    public int maxArea(int[] height) {
                int n=height.length;

        int i=0,j=n-1;
        int h,breadth;
        int area=0;
        while(i<j){
            breadth=Math.abs(i-j);
            h=Math.min(height[i],height[j]);
            area= Math.max(area, breadth*h);
            if(height[i]<height[j]){
                i++;
            }else if(height[i]>height[j]){
                j--;
            }else{
                i++;
                j--;
            }
        }
        return area;

    }
}