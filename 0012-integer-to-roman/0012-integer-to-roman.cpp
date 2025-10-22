class Solution {
public:
    string intToRoman(int num) {
        // V -> if we place I before V then it becomes IV ie 4
        // X=> if we place I before X then it becomes IX ie 9
        // L=> if we place X before L then it becomes XL ie 40
        // C=> if we place X before C then it becomes XC ie 90
        // D=> if we place C before D then it become CD ie 400
        // M=> if we place C before M then it become CM ie 900

    //    58
    //    choose 50
    //    times=58/50=1   "L"
    //    remainder=58%50=8
    //    choose 5
    //    times=8/5=1 "LV"
    //    remainder=8%5=3
    //    choose 1
    //    times=3/1=3 "LVIII"
    //    remainder=3%1=0

    // store all the values in descending order in vector 
//     vector<int> val{1000,900,500,400,100,90, 50, 40,10,9,5,4,1};
//     vector<string> sym{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
//     string result="";
//     for(int i=0;i<13;i++){
//         if(num==0) break;
//         int times=num/val[i];
//         // add the symbol times time 
//         while(times--){
//             result+=sym[i];
//         }
// num=num%val[i];
//     }

// return result;

// we can also make a pair 
vector<pair<int,string>>valSym{{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},{90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},{9, "IX"},{5, "V"},{4, "IV"},{1, "I"}};

            string result;
            for(auto [val,sym]:valSym){
                if(num==0) break;
                while(num>=val){
                    result+=sym;
                    num-=val;
                }
            }

            return result;
    }
};