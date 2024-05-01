class Solution {
   
public:
 typedef long long ll;
//   brute force:
//   find all substrings 
//   count frequency of char in each substring and check at most one letter appears odd times
// intuition
// for a good substring: 
// character from a to j should appear even time
// only one character from a to j should appear odd times and other characters should appear even times
// How to find substring in which characters has even times occurence?
// a^a=0 (even number of times) ^ -> xor
// a^a^a≠ 0 (odd number of times)
// representation of letters from a to j in binary,j i h g f e d c b a
// a-> 0 0 1
// b-> 0 1 0
// c-> 1 0 0
// d-> 1 0 0 0
// .
// .
// .
// j->1 0 0 0 0 0 0 0 0 0

// abbcc
// initially xor=0000
// if we see "a" for first time then  xor= 0000^001 =001( only a is present)
// when we see "b" for first time then xor= 001^010 =011 (a and b both are present as bot bits are set to 1)
// current xor value tells character present in the current substring
// when "b" comes again then xor =011^010 =001
// a    b   b 
// 001 011 001
// 001 ^ something =001 it means that something part has even number of characters and it's value is 0
// 001 has already occured in past it means it has occured even times

// same concept in terms of number
//             1 4 -6 2
// prefix sum: 1 5 -1 1  we encounter 1 again it means that sum of 4 -6 2 must be 0
// store the occurences of xor values in map, if xor value is already present in map then add the count to result
// when we encounter c xor= 001^100 =101
// when we encounter c again xor= 101^100=001
// a    b   b   c    c
// 001 011 001 101  001
// ↑        ↑        ↑
// map values
// 001->1->2->3   result=1+2   (wonderful substring ->even number of char)
// 001->1
// 101->1


// how to find 1 character with odd occurence ?
// at each index we will do the below step to find whether there is 1 character with odd occurence or not 
// let take a new character d
//                 a    b   b   c    c   d
// cumulative xor->001 011 001 101  001  1001
//  xor for d= 1000 ^0001=1001  store in map
//  bbccd is wonderful string
//  ex:d b b c d c d
//  d ^b ^b ^c ^d ^c ^d =d
//  now xor d with a b c d e f g h i j
//  when we xor d with d we get 0 else we get not equal to 0
//  it indicates that in particular string d has occured odd number of times
// same we can use here, to find the 1 character with odd ocurrence 
//                  a    b   b   c    c   d
// cumulative xor->001 011 001 101  001  1001
// xor the cumulative xor with (all the character from a to j)
// cummulativexor ^a =1001^001=1000 (check whether it's present in map or not , we have seen this in past or not)
// cummulativexor ^b =1001^010=1011
// cummulativexor ^c =1001^100=0101
// cummulativexor ^d =1001^1000=0001 (already present in map it means d has occured odd number of time in part "abbccd" and "d" and "bbccd")
// map values
// 000->1
// 001->1->2->3->4   result=1+2+3   (wonderful substring ->even number of char)
// 001->1
// 101->1  
// similarly for a   b   b c c 
//              001 011 001
//              cumulative xor ^(a to j) will tell whether abb is wonderful substring or not


// final dry run
// intially xor=000
//                  a    b   a
// cummulative xor:001 011 010
// map
// 000->1  
// in order to find 1 character with odd occurence
// when we are at index 0

// then xor the cummulative xor till index 0 with (a to j) and check whether its present in map or not
// if 001^001(a) =000 already present it means "a"
// map
// 000->1  
// 001->1
// index 1
// 011^001(a)=010
// 011^010(b)=001 it means that after a at 0 index there must be a substring where b has occured odd number of time

// map
// 000->1  
// 001->1
// 011->1
// at index=2
// 010 ^ 001(a) =011 (after b at index 1 it has occured odd nmuber of times)
//    and so on 
// map
// 000->1  
// 001->1
// 011->1
// 010->1

// how to find binary value of each character from a to j
// a-a=0
// b-a=1
// shift 0000000...1 by =ch-'a'
// 1<<shift
long long wonderfulSubstrings(string word) {
    unordered_map<ll,ll>mp;
    mp[0]=1;
    int cum_xor=0;
    ll result=0;
    for(auto ch: word){  //o(n)
        int shift=ch-'a';
        cum_xor^=1<<shift;
        result+=mp[cum_xor]; //all characters are even in count
        for(char ch1='a';ch1<='j';ch1++){ //o(10) for odd count
           int shift=ch1-'a';
           ll check_xor= (cum_xor ^ (1<<shift));
           result+=mp[check_xor];
        }
        mp[cum_xor]++;
    }
    return result;
    }
};

