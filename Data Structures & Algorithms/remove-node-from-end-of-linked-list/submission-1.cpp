/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy=new ListNode(-1);  //dummy for edge case handling
        dummy->next=head;
        ListNode* ptr1=dummy;
        ListNode* ptr2=dummy;

        //move ptr2 n steps away
        for(int i=0; i<n;i++){
            ptr2=ptr2->next;
        }
        //move both pointers until ptr2->next!=numm
        while(ptr2->next!=nullptr){
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }


        /*
         // remove nth node from end
        ListNode* toDelete = ptr1->next;
        ptr1->next = ptr1->next->next;
        delete toDelete;

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
        */
        //removing ptr1->next node 
        ptr1->next=ptr1->next->next;

        return dummy->next;



        


        
    }
};
