class Solution {
    public int maximumPopulation(int[][] logs) {
     int maxPop=0;
     int resultYear=0;

     for(int year=1950;year<=2050;year++){
        int count=0;
        for(int[] log: logs){
            if(year>=log[0] && year<log[1]){
                count++;
            }
            
        }
        if(count>maxPop){
            maxPop=count;
            resultYear=year;
        }
     }
     return resultYear;
        
    }
}