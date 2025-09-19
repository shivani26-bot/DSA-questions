// class MyCalendar {
//     // private: vector<pair<int,int>>bookings;
// public:
// vector<pair<int,int>>bookings;

//     MyCalendar() {}
    
//     bool book(int start, int end) {
//         for(auto val: bookings){
//              int existingStart=val.first;
//              int existingEnd=val.second;
//             if(existingStart<end && existingEnd>start) return false;
//         }
//         bookings.push_back({start,end});
//         return true;
//     }
// };


// emplace_back() is a C++ STL container method (like in std::vector, std::deque, etc.) that constructs a new element directly in place at the end of the container, instead of creating it first and then copying or moving it.
// push_back():
// You must already have an object, and it will be copied or moved into the container.
// std::vector<std::string> v;
// std::string s = "hello";
// v.push_back(s);        // copies s into v
// v.push_back("world");  // constructs temporary string then moves/copies into v
// emplace_back():
// Constructs the object in place, passing the constructor arguments directly to it. No temporary object, no extra copy/move.
// std::vector<std::string> v;
// v.emplace_back("hello");            // constructs "hello" in place
// v.emplace_back(5, 'x');             // constructs string("xxxxx") in place

class MyCalendar {
    private: vector<pair<int,int>>bookings;
public:


    MyCalendar() {}
    
    bool book(int start, int end) {
        for(const auto [s,e]: bookings){
       
            if(start<e && s<end) return false;
        }
        bookings.emplace_back(start,end);
        return true;
    }
};


// class MyCalendar {
 
// public:
// set<pair<int,int>>bookings;

//     MyCalendar() {}
    
//     bool book(int start, int end) {
//         // lowerbound find element >= start,end 
//         // find the first event that start after or at the same time {start,end }
//     auto it= bookings.lower_bound({start,end}); //logn
//     // check if current event overlaps with next event current->a2,b2 next->a3,b3, previous->a1,b1
//     if(it!=bookings.end() && it->first<end) return false;
//     // check if current event overlaps with previous event 
//     if(it!=bookings.begin()){
//         auto prevIt= prev(it);// returns previous iterator of current element
//         if(prevIt->second>start) return false;
//     }
//     // a1------------b1 a2--------------b2 a3--------------b3

//         bookings.insert({start,end});
//         return true;
//     }
// };

// /**
//  * Your MyCalendar object will be instantiated and called as such:
//  * MyCalendar* obj = new MyCalendar();
//  * bool param_1 = obj->book(start,end);
//  */
//             //  1
// //         a----------------------------------------------b      
// // 2   a-------------------b      a-----------------b 3
// // 4 a------------b s----------------------e a------------b 5
// //       a----------b 6                    a------------b 7
// // s->start e->end
// // a and b are possible start and end overlapping and non overlapping interbal 
// // in above diagram only 4,5,6,7 are non overlapping 
// // a<e && b>s  return false 

// // we can also apply binary search, but problem is we will have to sort the vector 
// // after every book call and then apply lower bound or upperbound to find the overlapping and non overlapping interval 

// // hence we can use set or map, because insertion, search uses logn here, it uses binary search internally, use ordered set or map then only we can use lower bound or upper bound 
// // {(10,20)(15,25)}
// // {(15,25)(10,20)(25,30)}
// // lower_bound will give element>=currelement 
// // lower_bound({10,20})= returns a pair where element >=10 and element>=20 , this gives the next element
// // but once we don't find the next element in set and iterator returns end then we should also make sure to check the previous element in the set
// // consider this example {(10,20)(15,25)};
