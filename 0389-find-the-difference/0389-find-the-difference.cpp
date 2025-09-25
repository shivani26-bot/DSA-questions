class Solution {
public:
    char findTheDifference(string s, string t) {
// // maintain a map to store the count of each element 
// unordered_map<char,int>count;
// // count all the characters in t first as t is longer than s 
// for(char c :t){
//     count[c]++;
// }

// // now traverse through s and decrease the count of element from the map if that element is present in map 
// for(char c: s){
//     count[c]--;
//     if(count[c]==0){
//         count.erase(c);
//     }
// }




// //at last only one extra element will be there in count map 
// return count.begin()->first;//return the element not the count for the element 
// Yes, when you XOR (^) two char values in C++, you are XORing their ASCII (or Unicode) integer values.
char res=0;
for(char c:s){
    res^=c;
    //xor each elment in s
}
for(char c:t){
    // xor each element in t, similar elements will cancel out 
    res^=c;
}
return res;


    }
};