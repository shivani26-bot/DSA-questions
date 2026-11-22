/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if(head==null || head.next==null) return head;

        ListNode prev=head;
        ListNode curr=head.next;

        while(curr!=null){
            // while(curr.val!=prev.val){
            //     prev=curr;
            //     curr=curr.next;
            // }
            if(curr.val==prev.val){
            while(curr!=null && curr.val==prev.val){
                curr=curr.next;
            }
            prev.next=curr;
            prev=curr;
            if(curr!=null)
            curr=curr.next;
            }else{
                prev=curr;
                curr=curr.next;
            }

        }
        return head;

        
    }
}