class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // sort(people.begin(),people.end());
        // int n=people.size();
        // int boat=0;
   
        // for(int i=0, j=n-1; i<=j;){
        //     // if(people[i]+people[j]<=limit && i!=j) {
        //         if(people[i]+people[j]<=limit) {
        //         i++;
        //         j--;
        //     }
        //     else{
        //       j--;
        //     }
        //     boat++;
        // }
        //   return boat;


        int n=people.size();
        sort(begin(people),end(people));
  
        int boat=0;
        int i=0,j=n-1;
        while(i<=j){
             
            if(people[i]+people[j]<=limit){
              
                i++;
               
            }
             boat++;
            j--;
        }
        return boat;
    }
};