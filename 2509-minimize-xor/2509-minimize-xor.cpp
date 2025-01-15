class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // int count=0;
        // while(num2){
        //     if(num2&1) count+=1;
        //     num2=num2>>1;
        // }
        int count=__builtin_popcount(num2);
          cout<<count<<endl;
      int x=0;
      for(int i=30;i>=0;i--){
   if(num1&(1<<i) && count){
    
        x=x|(1<<i);
        count--;

   }
  
      }
       cout<<count<<endl;
   for(int i=0;i<30;i++){
    if((x&(1<<i))==0 && count){
        x=x|(1<<i);
        count--;
    }
   }
      cout<<x<<endl;
      
        return x;
    }
};