class Solution {
    public ListNode partition(ListNode head, int x) {

        ListNode lessHead= new ListNode(0);
        ListNode greaterHead= new ListNode(0);

        ListNode lessTail= lessHead;
        ListNode greaterTail= greaterHead;

        ListNode curr=head;
        while(curr!=null){
            if(curr.val<x){
                lessTail.next=curr;
                lessTail=lessTail.next;
            }
            else{
                greaterTail.next=curr;
                greaterTail=greaterTail.next;
            }
            curr=curr.next;
        }

        lessTail.next=greaterHead.next;
        greaterTail.next=null;

        return lessHead.next;
        
    }
}