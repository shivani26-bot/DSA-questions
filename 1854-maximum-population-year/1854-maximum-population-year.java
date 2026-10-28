class Solution {
    public int maximumPopulation(int[][] logs) {
    //  int maxPop=0;
    //  int resultYear=0;

    //  for(int year=1950;year<=2050;year++){
    //     int count=0;
    //     for(int[] log: logs){
    //         if(year>=log[0] && year<log[1]){
    //             count++;
    //         }
            
    //     }
    //     if(count>maxPop){
    //         maxPop=count;
    //         resultYear=year;
    //     }
    //  }
    //  return resultYear;


    int[] delta= new int[101];

    for(int[] log: logs){
        delta[log[0]-1950]++;
        delta[log[1]-1950]--;
    }

    int runningSum=0;
    int maxPopulation=0;
    int resultYear=1950;

    for(int i=0;i<101;i++){
         runningSum+=delta[i];
         if(runningSum>maxPopulation){
            maxPopulation=runningSum;
            resultYear=1950+i;
         }

    }
    return resultYear;
        
    }
}