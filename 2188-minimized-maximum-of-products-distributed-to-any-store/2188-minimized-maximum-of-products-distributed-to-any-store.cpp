class Solution {
public:
bool isPossibleToDistribute(int n,int mid,  vector<int>& quantities){

    // for(int i=0;i<quantities.size();i++){
    //      int req_store= ceil((double)quantities[i]/mid);
    //     // int req_store=(quantities[i]+mid-1)/mid;
    //     if(n<req_store) return false;
    //     n=n-req_store;

    //     // using the ceil method directly, you will get a wrong answer because by default the divison in c++ is interger divison which will result in ignoring the fractional part and ceil fails to perform as we intended it to, so just typecast double inside the function(stores -= ceil((double) products / quantity);) to get the right answer else the alternate method is the best to use.
    //     //    n-=ceil((double)quantities[i]/mid);
    //     //        n-=(quantities[i]+mid-1)/mid;  //ceil can be written as 
    //     //  if(n<0) return false;
    // }
    // return true;

    int actualStores=0;
      for(int i=0;i<quantities.size();i++){
        
         int req_store= quantities[i]/mid;
if(quantities[i]%mid!=0) req_store++;
      actualStores+=req_store;
    }
    return actualStores<=n;
}
    int minimizedMaximum(int n, vector<int>& quantities) {
        // binary search on answer 
        // we can take range from 1 to max_elements(quantites)
        // check for every range element whether its possible to 
        // distribute all the products to every store 
        // n = 7, quantities = [15,10,10]
        // if decide giving 4 products
        // 4 4 4 3,4 4, 2 we cant distribute to all the products to 7 stores
        // 5 5 5,5 5,5 5
        // hence 5 and number above 5 will be easily distributed
        // here we are taking answer and finding whether it can be the possible anwer or not 

        int low=1;
        int high=*max_element(quantities.begin(),quantities.end());
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            // target=quantities[i]
            if(isPossibleToDistribute(n,mid,quantities)){
                ans=mid;
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        } 
        return ans;
    }
};