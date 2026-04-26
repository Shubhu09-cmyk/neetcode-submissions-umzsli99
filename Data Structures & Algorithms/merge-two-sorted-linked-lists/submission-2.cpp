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
/* this is by recursion
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;  //to avoid segmentation fault
        if(list1->val <= list2->val){
            list1->next=mergeTwoLists(list1->next,list2);  //recursion
            return list1;
        }
        else{
            list2->next=mergeTwoLists(list1, list2->next);
            return list2;
        }
        
    }
*/
//using two pointer approach most optimal
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        /*
          ListNode dummy(-1);
    ListNode* temp = &dummy;
*/
        ListNode* dummy=new ListNode(-1);  //direct heap it won't delete
        ListNode* t1=list1;
        ListNode* t2=list2;
        ListNode* temp=dummy;
        while(t1!=nullptr && t2!=nullptr){
            if(t1->val<t2->val){
                temp->next=t1;
                temp=t1;    //better to write. temp=temp->next
                t1=t1->next;
            }
            else {
                temp->next=t2;
                temp=t2;
                t2=t2->next;
            }
        }
        if(t1==nullptr){
            temp->next=t2;
        }else{
            temp->next=t1;
        }
        return dummy->next;
    }
};
