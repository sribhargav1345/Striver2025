class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* a = head;

        int ct = 0;
        while(a!=NULL)
        {
            ct++;
            a = a -> next;
        }

        //cout<<ct<<endl;
        if(ct==1) return a;

        a = head;

        int f = ct - n;
        int i=1;

        while(i<f)
        {
            a = a -> next;
            i++;
        }

        if(i>f)
        {
            ListNode* b = a -> next;
            a -> next = NULL;

            return b;
        }

        // Next element remove cheyyali
        ListNode* b = a -> next;
        a -> next = a -> next -> next;
        b -> next = NULL;

        return head;
    }
};