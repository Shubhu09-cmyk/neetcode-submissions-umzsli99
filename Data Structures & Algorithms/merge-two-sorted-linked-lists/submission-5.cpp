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
Time:
Still O(n + m)
Space:
O(n + m) (due to recursion stack)


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

//O(n + m). time. ;;; space O(1)
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        /*
          ListNode dummy(-1);
    ListNode* temp = &dummy;
*/
        ListNode* dummy=new ListNode(-1);  //direct heap it won't delete This allocates memory on the heap and never deletes it → minor memory leak.
        ListNode* temp=dummy;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val<list2->val){
                temp->next=list1;
                temp=list1;    //better to write. temp=temp->next
                list1=list1->next;
            }
            else {
                temp->next=list2;
                temp=list2;
                list2=list2->next;
            }
        }
        if(list1==nullptr){
            temp->next=list2;
        }else{
            temp->next=list1;
        }
        return dummy->next;
    }
};
