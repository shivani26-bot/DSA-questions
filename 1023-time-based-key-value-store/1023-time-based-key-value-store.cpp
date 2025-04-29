// Always use const string& + initializer list for constructor parameters unless you want to modify the passed string (which is rare).
class TimeStampedValue{
    public:
    int timestamp;
    string value;
//     Here, you are taking a non-const reference (string& value).
// Meaning: the caller must pass a modifiable string (not const).
// You assign it inside the constructor.
// ❌ Problem: You cannot pass a temporary string (like "abc") because it's const by nature.

// Also, accidentally modifying value inside the constructor could modify the caller's original string — risky.
    TimeStampedValue(int timestamp,string& value){
        this->timestamp=timestamp;
        this->value=value;
    }
    // TimeStampedValue(int timestamp, const string& value)
        // : timestamp(timestamp), value(value) {}
// Here, you are taking a const reference (const string& value).
// Meaning: the caller can pass any string, even temporaries like "abc"
// You cannot modify value inside the constructor — safe.
// You are using an initializer list (: timestamp(timestamp), value(value)), which is more efficient — no default constructor + assignment overhead.
// ✅ Highly recommended for passing input parameters like strings, especially in constructors.
};

class TimeMap {
public:
  map<string,vector<TimeStampedValue>> mp;
    TimeMap() {
        
    }

    void set(string key, string value, int timestamp) {
//         TimeStampedValue(timestamp, value)
// This creates a temporary object of type TimeStampedValue, and it's immediately passed to push_back.

        mp[key].push_back(TimeStampedValue(timestamp,value));
    }
    
    string binarySearchTimestamp(vector<TimeStampedValue>&arr, int target){
        int l=0;int h=arr.size()-1;
        string ans="";
        while(l<=h){
            int mid=l+(h-l)/2;
TimeStampedValue curr=arr[mid];

if(curr.timestamp<=target){
    ans=curr.value;
    l=mid+1;
}
else h=mid-1;
        }
        return ans;
    }
    string get(string key, int timestamp) {
        if (!mp.count(key)) {
            return "";
        }
    //    vector<TimeStampedValue>& timeStampedValues=mp[key];
    return binarySearchTimestamp(mp[key],timestamp);
    }
};
// class TimeMap {
// public:
//     unordered_map<string, map<int, string>> maps;
//     TimeMap() {
        
//     }
//     //if the timestamp doesn't exist when you try to retrieve the key for given key in the map then return the latest timestamp value, 
//     // foo->(bar,1)(bar2,5)
//     // get(foo,4) return the latest ie 1,because foo with timestamp 4 is not present hence decrement the timestamp until you find the latest one

//     // make a map to store key value pairs, inside the map, for each key also make a map, where for different time stamp ,value will be present 
// //     key-> timestamp->v1
// //                      v2...

// //    foo->  1->bar
// //           5->bar2
// //    blah-> 8->moon

// //    get(foo,4)
// //    take the inside map value for foo
// //    1->bar
// //    5->bar2
// //    we didn't find 4 here, this map is ordered, keys or timestamps are arranged in acending order, find the upper value for 4 ie 5 and then start decrementing the iterator and return the ans
// // and also when we are setting the key and values, the time stamp will always be increasing for that key in the input (we can also store it in map of string to vector<pair<int,string>>)
//             // 0        1        2
// // foo-> [{bar,1}, {bar2,5},{noon,8}]
// // get(foo,5)
// // get(foo,4)
// // use binary search to find the target 
//     void set(string key, string value, int timestamp) {
//         maps[key][timestamp] = value;
//     }
    
//     string get(string key, int timestamp) {
//         if (!maps.count(key)) {
//             return "";
//         }
//         auto it = maps[key].upper_bound(timestamp);
//         if (it != maps[key].begin()) {
//             return (--it)->second;
//         } else {
//             return "";
//         }
//     }
// };


