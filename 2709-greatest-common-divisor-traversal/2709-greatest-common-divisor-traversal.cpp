int ct;
const int MAX=1e5+5;
 bool prime[MAX];
int spf[MAX]; 
// Without the static keyword, spf has external linkage by default.
// External linkage means that the variable can be accessed by other translation units (source files) if they declare it using the extern keyword.
// The variable spf still has static storage duration, meaning it exists for the entire duration of the program's execution.  
// The static keyword here indicates that the variable spf has internal linkage and static storage duration.
// Internal linkage means that the variable is only accessible within the translation unit (source file) where it is declared.
// Static storage duration means that the variable exists for the entire duration of the program's execution. 
// SMALLEST PRIME FACTOR
void sieve(){
   
// Declare MAX as a static const

    // Make prime static
 

    fill(prime, prime+MAX,true);
    for(int i=2;i<MAX;i++){
    spf[i]=i;
    }
    prime[0]=prime[1]=false;
    for(int i=2;i*i<MAX;i++){
        if(prime[i]==1){
            for(int j=i;j*i<MAX;j++){
                if(prime[i*j])
                spf[i*j]=i;
                prime[i*j]=false;
            }
        }
    }

}

vector<int>getFactorization(int x){
    vector<int>primeFactors;
    unordered_map<int,int>mp;
    while(x!=1){
        mp[spf[x]]++;
        x=x/spf[x];
    }
    for(auto it: mp) primeFactors.push_back(it.first);
    return primeFactors;
    
    }


void dfs(int node, unordered_map<int,vector<int>>& uedges, vector<bool>&vis){
    if(vis[node]) return;
    vis[node]=true;
    ct++;
    for(auto it: uedges[node]){
        if(!vis[it])
        dfs(it, uedges,vis);
    }
}

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        // we want all the pairs to be directly or indirectly connected to each other
        // use Sieve of Eratosthenes to find smallest prime factor of each number
        sieve();
        int n=nums.size();
        // now map number present on each index with its prime factors
        unordered_map<int, vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[i]=getFactorization(nums[i]);
        }
        // now reverse map the above map and map each factor with indexes whose number include that factor
        unordered_map<int,vector<int>>rmp;
        for(auto p:mp){

            for(auto it: p.second)
                rmp[it].push_back(p.first);
            }
            // now go on all values of reverse map and build connection (undirect edge)
            // we can use dfs or dsu , better use dfs for short code
            unordered_map<int,vector<int>>uedges;
            for(auto p:rmp){
                vector<int>indexes=p.second;
                if(indexes.size()<=1) continue;

                for(int i=1;i<indexes.size();i++){
                    int u=indexes[i-1];
                    int v=indexes[i];
                    uedges[u].push_back(v);
                    uedges[v].push_back(u);        
                }
                }
                vector<bool>vis(n,0);
                 ct=0;
                dfs(0,uedges,vis);
                if(ct==n) return true;
               return false;

      
    }
};
