class Solution {
public:
    int findComplement(int num) {
      int temp=num;
      int countBits=0;
      while(temp>0){
        countBits++;
        temp=temp>>1;
        
      }
cout<<countBits<<endl;

for(int i=0;i<countBits;i++){
      int mask=(1<<i);
        num= num^mask;
        cout<<num<<endl;
}
        return num;
    }
};