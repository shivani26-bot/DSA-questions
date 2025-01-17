class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {

        // x^y=z
        // // if we xor any two numbers we can find the third number 
        // (x^y)^y=z^y => z^y=x
        // (x^y)^x=z^x => z^x=y
        // derived ={0,1,0,0,1,0}
        // original={a,b,c,d,e,f}
        // a^b=0
        // a^b^b=0^b
        // a=0^b
        // if we take a=0
        // then we can find b, as xor of any two numbers, can give the third number
        // a^0=b=>0^0=b=>b=0
       
        // derived ={0,1,0,0,1,0}
        // original={0,0,c,d,e,f}
        //          {0,0,1,d,e,f}
        //          {0,0,1,1,e,f}
        //          {0,0,1,1,1,f}
        //          {0,0,1,1,1,0}
        
        // if we take a=1;
        //   derived ={0,1,0,0,1,0}
        //   original={1,b,c,d,e,f}
        //            {1,1,c,d,e,f}
        //            {1,1,0,d,e,f}
        //            {1,1,0,0,e,f}
        //            {1,1,0,0,0,f}
        //            {1,1,0,0,0,1}

        // derived=[1,0,1,1]
        // if we take original[0]=0
        // origianl={0,1,1,0}
        // if we take original[0]=1
        // origianl={1,0,0,1}

        // take original[0]=0
        // build original array
        // check original[n-1]^original[0]==derived[n-1]
        //  take original[0]=1
        // build original array
        // check original[n-1]^original[0]==derived[n-1]

        // original[i]^original[i+1]=derived[i]
        // derived[i]^original[i]=orignal[i+1]
        int n=derived.size();
        vector<int>original(n);
        // first try with original[0]=0
        original[0]=0;
        for(int i=0;i<n-1;i++){
            original[i+1]=derived[i]^original[i];
        }
        if(derived[n-1]==original[n-1]^original[0]) return true;

   //  try with original[0]=1
        original[0]=1;
        for(int i=0;i<n-1;i++){
            original[i+1]=derived[i]^original[i];
        }
        if(derived[n-1]==original[n-1]^original[0]) return true;

        return false;
    }
};