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
    void reorderList(ListNode* head) {
   if(head==nullptr ||head->next==nullptr){   //if no or 1 element
    return;
   }

   //step-1 find the middle element by floyd warshall algo
   ListNode* p1=head;
   ListNode* p2=head;
   while(p2->next!=nullptr && p2->next->next!=nullptr){
    p1=p1->next;       //p1 will be the middle element
    p2=p2->next->next;
   }

   //reversing the second half
   ListNode* second=p1->next;     
   p1->next=NULL;
   ListNode* prev=nullptr;

   while(second!=nullptr){
    ListNode* temp=second->next;
    second->next=prev;
    prev=second;      
    second=temp;
   }
    //merging two LL
    ListNode* first=head;
    second=prev;   //prev gives the head of reversed second part at the end of 
     while(second!=nullptr){
    ListNode* temp1=first->next;
    ListNode* temp2=second->next;

    first->next=second;
    second->next=temp1;

    first=temp1;
    second=temp2;

   }
        
    }
};
