class Solution {
public:
unordered_map<int,string>belowTen={{0,""},{1,"One"},{2,"Two"},{3,"Three"},{4,"Four"},{5,"Five"},{6,"Six"},{7,"Seven"},{8,"Eight"},{9,"Nine"}};
unordered_map<int,string>belowTwenty={{10,"Ten"},{11,"Eleven"},{12,"Twelve"},{13,"Thirteen"},{14,"Fourteen"},{15,"Fifteen"},{16,"Sixteen"},{17,"Seventeen"},{18,"Eighteen"},{19,"Nineteen"}};
unordered_map<int,string>belowHundred={{1,"Ten"},{2,"Twenty"},{3,"Thirty"},{4,"Forty"},{5,"Fifty"},{6,"Sixty"},{7,"Seventy"},{8,"Eighty"},{9,"Ninety"}};

string solve(int num){
    if(num<10){
        return belowTen[num];
    }
    if(num<20){
        return belowTwenty[num];
    }
  if(num<100){ //89 -"Eighty nine"
    return belowHundred[num/10] +((num%10!=0)? " "+ belowTen[num%10] :"");
  }
if(num<1000){ //879 -"Eight hundred seventy nine"
 return solve(num/100) + " Hundred" + ((num%100!=0)? " "+ solve(num%100) :"");
}
if(num<1000000){
  return solve(num/1000) + " Thousand" + ((num%1000!=0)? " "+ solve(num%1000) :"");  
}
if(num<1000000000){
  return solve(num/1000000) + " Million" + ((num%1000000!=0)? " "+ solve(num%1000000) :"");  
}
  return solve(num/1000000000) + " Billion" + ((num%1000000000!=0)? " "+ solve(num%1000000000) :"");  

}
    string numberToWords(int num) {
//         1 to 9, 10 to 19 are special number hence we will store english words          
//         corresponding to these numbers in the map
//         20 to 99 , number at tens position has naming like twenty, thirty, forty, fifty
//         sixty, seventy, eighty , ninety.
//         store the english word corresponding to number at tens positin in map for 20 to 99
//         for ex: 2 at tens position will be twenty
//                 3 at tens position will be thirty
//                 4 at tens position will be forty
//                 5 at tens position will be fifty and so on

//                 900
//                 at hundredth position we have 9, call the solve for(900%100) and check
//                 if 900%100 !=0 then only u can call solve for this other wise return 
//                ""
//    9995
//    9995/1000 = solve(9995 /1000) nine + thousand + solve(9995%1000 ie 995)
//    98,995 /1000= 98
//    solve(98,995 /1000) + thousand + solve(98,995 %1000)
// if number is less than 1000 append hundred in between, number/100 to find the left most bit
// if number is less than 100,000 append thousand in between, number/1000 to find the left most bit
// if number less than 100,000,000 append million in between, number/100000 to find the left most bit
// if number greater than 100,000,000 append billion in between
// 231 - 1 => 2147483647
if(num==0){
    return "Zero";
}
return solve(num);

    }
};