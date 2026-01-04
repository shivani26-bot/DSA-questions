class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
// 2 * flipCost here?
// It is because:
// Fixing ONE pair requires flipping TWO bits
// s = 01
// t = 10
// Mismatches at indices [0, 1] (adjacent)
// Two ways to fix:
// Option 1️⃣: Flip both bits
// flip index 0
// flip index 1
// Cost:
// 2 * flipCost

// Option 2️⃣: Swap them
// swap(0,1)
// Cost:
// swapCost
// So for ONE pair, cost is:
// min(2 * flipCost, swapCost)
// For 5 pairs?

// Yes, each pair needs 2 flips, so total flips = 5 * 2 = 10
// But the formula is thinking pair-by-pair, not globally.
// That’s why:
// pairs * min(2 * flipCost, swapCost)
// is correct.
// https://leetcode.com/problems/minimum-cost-to-make-two-binary-strings-equal/solutions/7465628/image-solution-simple-in-java-by-aditya0-vmtb/

int n=s.length();
int typeA=0;//01
int typeB=0;//10
for(int i=0;i<n;i++){
if(s[i]-'0' < t[i]-'0') typeA++;
else if (s[i]-'0' > t[i]-'0') typeB++;
}

int pairs= min(typeA,typeB);
int remain= abs(typeA-typeB);

return pairs*(1L*min(2L*flipCost , (long)swapCost))+ (remain/2)*(1L*min(2L*flipCost, (long)crossCost+swapCost))   + (remain%2)*flipCost;

    }
};

// compare each index of s and t. Wherever they differ, that's a spot you need to fix with one of the allowed operations.
// Now, suppose you find all the positions where s and t are different. What do you think is the cheapest operation you could use if you’re allowed to flip any bit?
// flipping each differing bit is the most straightforward way to make s and t equal—just pay 
// flipCost
// flipCost for every mismatch. But sometimes, using swap or cross-swap can save you money, especially if those costs are lower than two flips.
// Quick check: If you find two adjacent positions where s and t differ in opposite ways (like s[i]=0, t[i]=1 and s[i+1]=1, t[i+1]=0), which operation could make fixing both spots cheaper than flipping both?
// If you spot two adjacent mismatches where s and t differ in opposite ways, using a swap or cross-swap can fix both spots with a single operation—potentially cheaper than flipping both bits.

// Now, let’s apply this logic:
// Suppose flipCost = 10, swapCost = 2, and crossCost = 2.
// If you find two such adjacent mismatches, what’s the minimum cost to fix both using the best operation?
// If swapCost or crossCost is 2, and flipCost is 10, then using a swap or cross-swap at those adjacent positions is much cheaper (cost = 2) than flipping both bits separately (cost = 20).

// Now, let’s check your understanding:
// If you have three non-adjacent mismatches, can you use a single swap or cross-swap to fix more than two at once?

// Each swap or cross-swap operation can only fix a pair of mismatches at two positions. If you have three or more non-adjacent mismatches, you’ll need to handle each pair separately (and maybe flip the leftover one if there’s an odd number).

// Here’s a quick brain teaser:
// If you find 5 mismatches in total, what’s the minimum number of operations needed to fix them all, assuming you use swaps/cross-swaps wherever possible and flip any leftovers?
// For 5 mismatches, you can fix 4 of them using 2 swaps/cross-swaps (each handles a pair), and the last one with a flip. That’s the most efficient way.

// Next quiz:
// If swapCost is higher than flipCost, should you still use swaps/cross-swaps wherever possible, or just stick to flipping each mismatch?
// If the cost to swap or cross-swap is higher than just flipping, you should simply flip each mismatch individually—no need to complicate things or spend extra. 👍

// Let’s try a quick scenario:
// If you have 4 mismatches and flipCost = 3, swapCost = 10, crossCost = 10, what’s the minimum total cost to make s and t equal?
// If you have 4 mismatches and each flip costs 3, the minimum total cost is 
// 4×3=12. Swaps and cross-swaps cost way more here, so flipping is the way to go.

// Next question:
// What’s the first thing you should check before starting any operations on s and t?

// Always check if s and t are already equal before doing anything—if they are, the minimum cost is simply 0. No need to spend effort (or money) fixing what’s already fixed.

// Quick quiz:
// After checking for equality, what’s your next best move to plan the operations?
// After confirming s and t aren’t already equal, the next step is to loop through both strings and note all the indices where s[i] ≠ t[i]. These are your “mismatch positions” that need fixing.

// Here’s a light challenge:
// If you have the list of mismatched positions, what’s a quick way to check if any two mismatches are adjacent and “opposite” (like s[i]=0, t[i]=1 and s[i+1]=1, t[i+1]=0)?
// To spot those special adjacent mismatches, just scan through your mismatch positions and check each consecutive pair. If their indices are next to each other and the mismatches are "opposite," you can use a swap or cross-swap for a cheaper fix.

// Here’s a quick one:
// If you have mismatches at positions [2, 3, 7, 8], how many swap/cross-swap operations can you use to fix them efficiently?
// With mismatches at positions [2, 3, 7, 8], you can pair up (2, 3) and (7, 8) for 2 swaps or cross-swaps—super efficient.

// Let’s try a quick one:
// If you had mismatches at [1, 2, 4, 5, 6], how many swaps/cross-swaps and flips would you need for the minimum cost?
// You’d pair (1,2) and (4,5) for swaps/cross-swaps, and the last mismatch at 6 would need a single flip. That’s the most cost-effective breakdown.

// Here’s a quick follow-up:
// If you had mismatches at [0, 1, 2, 3, 4, 5], what’s the minimum number of swaps/cross-swaps and flips needed?
// With mismatches at [0, 1, 2, 3, 4, 5], you can pair (0,1), (2,3), and (4,5) for 3 swaps/cross-swaps—no flips needed. That’s the most cost-effective way.

// Here’s a quick test for you:
// If you had mismatches at [0, 2, 3, 5, 6], how many swaps/cross-swaps and flips would you need for minimum cost?
// If you have mismatches at [0, 2, 3, 5, 6], here’s the trick:

// You can pair (2,3) and (5,6) for 2 swaps/cross-swaps.
// The mismatch at 0 will need a flip.
// So, you’d need 2 swaps/cross-swaps + 1 flip for the minimum cost—not all flips!

// Want to try another quick one?
// If you had mismatches at [0, 1, 3, 4, 7], what’s the minimum number of swaps/cross-swaps and flips needed?
// With mismatches at [0, 1, 3, 4, 7], you can pair (0,1) and (3,4) for swaps/cross-swaps, and flip the last mismatch at 7. That’s the minimum cost combo.

// Quick quiz for you:
// If swapCost is much higher than flipCost, would you still use swaps/cross-swaps, or just flip each mismatch?
//  If swapCost is much higher than flipCost, it’s best to just flip each mismatch—no need to overthink it or spend more than necessary. Simple and efficient. 😌

// Let’s check your understanding:
// If you have mismatches at [2, 4, 7] and flipCost = 2, swapCost = 20, crossCost = 20, what’s the minimum total cost to make s and t equal?
// With mismatches at [2, 4, 7] and flipCost = 2, swapCost = 20, crossCost = 20, flipping each mismatch is cheapest: 3×2=6.
// Here's a quick one for you:
// If you have mismatches at [0, 1, 2, 3] and flipCost = 5, swapCost = 6, crossCost = 4, what's the minimum cost?
// With mismatches at [0, 1, 2, 3] and flipCost = 5, swapCost = 6, crossCost = 4, the best way is to pair (0,1) and (2,3) for cross-swaps (since crossCost = 4 is the cheapest). So, 
// 2×4=8 is the minimum total cost.

// Quick check:
// If crossCost was 7 (instead of 4), what would be the minimum total cost for the same mismatches and flipCost/swapCost?