class Solution {
public:
    int hammingDistance(int x, int y) {
        //count set bits concept
        int Xor= x^y;
        cout<<Xor;

int count=0;

while(Xor){

  Xor=((Xor) & (Xor-1));
  count++;
}
        return count;


    }
};