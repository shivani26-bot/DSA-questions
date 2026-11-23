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
    public ListNode deleteMiddle(ListNode head) {
        // if(head.next==null) return null;//only one element

        // int count=0;
        // ListNode curr= head;
        // while(curr!=null){
        //     count++;
        //     curr=curr.next;
        // }
        // int mid=count/2;
        // curr=head;
        // for(int i=0;i<mid-1;i++){
        //     curr=curr.next;
        // }

        // //curr will stop just before the middle element
        // curr.next=curr.next.next;

        // return head;

                if(head.next==null) return null;

        ListNode slow=head;
        ListNode fast= head.next.next;

        while(fast!=null && fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }

        slow.next=slow.next.next;
        return head;


    }
}