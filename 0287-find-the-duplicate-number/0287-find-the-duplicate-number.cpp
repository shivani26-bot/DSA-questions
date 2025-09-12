class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // we can use binary search 
        // int n=nums.size();
        // int low=1;
        // int high=n;
        // while(low<=high){
        //     int mid=(low+high)/2;
        //     int countEle=0;
        //     for(auto it:nums){
        //         if(it<=mid) countEle++;

        //     }
        //     if(countEle<=mid) low=mid+1;
        //     else high=mid-1;
        // }
        // return low;

//         Initialize two pointers, slow and fast, to the first element of the input list nums.
// Iterate through the list using the Floyd's Tortoise and Hare algorithm(See below) to find a cycle.
// Once a cycle is found, reset one of the pointers to the beginning of the list and continue iterating until both pointers meet again.

// Detailed Explanation:

// Initialize slow and fast pointers to the first element of the input list nums.
// Enter a loop to detect a cycle:
// a. Update slow to the next element using nums[slow].
// b. Update fast to the next element after nums[fast], effectively moving two steps.
// c. Check if slow is equal to fast. If they are equal, a cycle has been found, and exit the loop.
// After finding the cycle, reset one of the pointers (slow2) to the beginning of the list.
// Enter a loop to find the duplicate element:
// a. Update slow using nums[slow].
// b. Update slow2 using nums[slow2].
// c. Continue this process until slow is equal to slow2, which represents the duplicate element.
// Return the duplicate element found (slow).

// Floyd's Tortoise and Hare algorithm
// Floyd's Tortoise and Hare algorithm, also known as Floyd's Cycle Detection algorithm, is an algorithm used to detect loops (cycles) in data structures like linked lists or arrays. It has been proven to reliably detect cycles under specific circumstances and can be applied to finding duplicate elements.

// This algorithm employs two pointers, referred to as the "tortoise" and the "hare," to traverse the list.

// Tortoise: A pointer that advances one step at a time through the list.
// Hare: A pointer that advances two steps at a time through the list.
// Using these pointers, you progress until the hare catches up with the tortoise or a cycle is detected.

// Here's an overview of the algorithm:

// Phase 1 (Cycle Detection):
// Move the tortoise and hare, advancing the hare twice as fast as the tortoise, until the hare catches up with the tortoise or a cycle is detected. If a cycle is detected, reset the tortoise and move the hare back to its position before the reset.

// Phase 2 (Cycle Start Detection):
// Move the tortoise and hare one step at a time until they match again. The position where they match again is the starting point of the cycle, corresponding to the duplicate element.

// Let's explain why this works for the problem at hand:

// Properties of Floyd's Tortoise and Hare Algorithm:
// The algorithm ensures that the tortoise and hare will match again at some position in the list. Exploiting this property, if a cycle exists, the tortoise and hare will certainly match at some position within the cycle.

// Relation between Duplicate Element and Cycle:
// In the presence of a duplicate element, the duplicate corresponds to the starting point of the cycle. Starting from the first element as the tortoise, and moving through the duplicates until reaching a duplicate (cycle start), the hare will join, and the tortoise and hare will match again inside the cycle.

// Therefore, the Floyd's Tortoise and Hare Algorithm provides an efficient and reliable way to find duplicate elements.

// We can apply the same algorithm to Linked List cycle Ⅱ

int slow=nums[0];
int fast=nums[0];
//first find the starting point of the cycle
while(true){
    slow=nums[slow];//1 steps
    fast=nums[nums[fast]];//2 steps
    if(slow==fast) break;
}
int slow2=nums[0];
while(slow!=slow2){
    slow=nums[slow];
    slow2=nums[slow2];
}
return slow;
    }
};