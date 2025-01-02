class Solution {
public:
    int maxScore(string inputStr) {

        // brute force 
        // 011101
        // we can split in the range 0 to n-2
// int n=inputStr.length();
// int maxScore=INT_MIN;
// int count0=0;
// for(int i=0;i<n-1;i++){
//     if(inputStr[i]=='0')
//     count0++;

//     int count1=0;
//     for(int j=i+1;j<n;j++){
        
//        if(inputStr[j]=='1')
//        count1++;
//     }
 
//     maxScore=max(maxScore,count0+count1);
// }
// return maxScore;

// int n=inputStr.length();
// int total_ones=0;
// // for(int i=0;i<n;i++){
// //     if(inputStr[i]=='1') total_ones++;
// // }
// total_ones=count(begin(inputStr),end(inputStr),'1');
// int zero=0;
// int one=0;
// //zero and one maintains number of zero and one in left substring
// int rightSideOne=0;
// int maxScore=INT_MIN;
// for(int i=0;i<n-1;i++){
// if(inputStr[i]=='0'){
//     zero++;
// }
// if(inputStr[i]=='1'){
//     one++;
// }
// rightSideOne=total_ones-one;
// maxScore=max(maxScore, zero+rightSideOne);
// }
// return maxScore;

// score=Zl+Or
// Zl->total zero in lhs
// Or-> total one in rhs
// Ot=Ol+Or
// Ot->total one in string
// Ol->toal one in lhs
// Or->total one in rhs
// score=Zl+(Ot-Ol)
// score=(Zl-Ol) + Ot
// maximize zl-ol
int total_ones=count(begin(inputStr),end(inputStr),'1');
int zero=0;
int one=0;
int n=inputStr.length();

int maxScore=INT_MIN;
for(int i=0;i<n-1;i++){
if(inputStr[i]=='0'){
    zero++;
}
if(inputStr[i]=='1'){
    one++;
}

maxScore=max(maxScore, zero-one);
}
maxScore=maxScore+total_ones;
return maxScore;


//         int n=inputStr.length();
//         vector<int>prefixZero(n,0);
//         vector<int>suffixOne(n,0);
//         if(inputStr[0]=='0') prefixZero[0]=1;
//          if(inputStr[n-1]=='1') suffixOne[n-1]=1;
//         for(int i=1;i<n;i++){
//                 if(inputStr[i]=='0') 
//                  prefixZero[i]=1+prefixZero[i-1];
//                 else prefixZero[i]=prefixZero[i-1];
//         }
//      for(int i=n-2;i>=0;i--){
//                 if(inputStr[i]=='1') 
//                  suffixOne[i]= 1+suffixOne[i+1];
//                 else suffixOne[i]=suffixOne[i+1];
//         }
//         // for(int i=0;i<n;i++){
//         //     cout<<prefixZero[i]<<" ";
//         // }
//         // cout<<endl;
//         //  for(int i=0;i<n;i++){
//         //    cout<<suffixOne[i]<<" ";
//         // }
//         //   cout<<endl;
// // "1111" "00"
//           if((prefixZero[n-1]==0 && suffixOne[0]==n)|| (prefixZero[n-1]==n && suffixOne[0]==0)) return n-1;
//              if(n==2 && prefixZero[0]==0 && suffixOne[n-1]==0) return 0;  //"10"
//              if(n==2 && prefixZero[0]==1 && suffixOne[n-1]==1) return 2;  //"01"
//         int score=0;
//         int maxScore=INT_MIN;
//         for(int i=1;i<n-1;i++){ //"0100"
//             score=prefixZero[i]+suffixOne[i];
//             maxScore=max(score, maxScore);
//         }
//         return maxScore;
    }
};