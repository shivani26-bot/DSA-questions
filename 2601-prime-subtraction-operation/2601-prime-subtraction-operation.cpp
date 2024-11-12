class Solution {
public:

// sieve Eratosthenes
//o(1) because we have taken fixed size of primes ie 1000
// if prime would be m, then time will be o(m*loglogm)
bool is_prime[1000];
void isPrime(){
    fill(is_prime, is_prime+1000, true);
    is_prime[0]=false;//false;
    is_prime[1]=false;//false;
for(int i=2;i*i<1000;i++){
   if(is_prime[i]==true){
    for(int j=i;j*i<1000;j++){
        is_prime[i*j]=false;
    }
    }
}
}
    bool primeSubOperation(vector<int>& nums) {
        int n=nums.size();
        isPrime(); //if is_prime[i]==0 then i is not a prime number
        // and if is_prime[i]=1 then i is a prime number 
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]) continue;

            // nums[i]>=nums[i+1]
            for(int p=2;p<nums[i];p++){
                if(!is_prime[p]) continue;
                  if(nums[i]-p<nums[i+1]){
                    nums[i]-=p;
                    break;
                  }
            }
            if(nums[i]>=nums[i+1]) return false;
        }
        return true;

    }
};