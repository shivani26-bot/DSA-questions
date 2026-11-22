/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {

    // private int getLinkedListLength(ListNode headA){
    //     int length=0;
    //     while(headA!=null){
    //         length++;
    //         headA=headA.next;
    //     }

    //     return length;
    // }

    //  public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
    //    int lengthA= getLinkedListLength(headA);
    //    int lengthB= getLinkedListLength(headB);
    //    while(lengthA>lengthB){
    //     lengthA--;
    //     headA=headA.next;
    //    }
    //    while(lengthA<lengthB){
    //     lengthB--;
    //     headB=headB.next;
    //    }

    //     while(headA!=null && headB!=null){
    //        if(headA==headB) return headA;
    //         headA=headA.next;
    //           headB=headB.next;
    //     }

    //     return null;
        
    // }
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        Set<ListNode> st= new HashSet<>();

        while(headA!=null){
            st.add(headA);
            headA= headA.next;
        }

        while(headB!=null){
            if(!st.add(headB)) return headB;
            headB=headB.next;
        }

        return null;
        
    }
}