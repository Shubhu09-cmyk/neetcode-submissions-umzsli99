/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //edge case if head =null
        if(head==nullptr){
            return NULL;
        }

        //STEP-1. create a new list with same values embedded in same LL
        Node* curr=head;
        
        while(curr!=nullptr){
            Node* newNode= new Node(curr->val);
            newNode->next=curr->next;
            curr->next=newNode;
            curr=newNode->next;
        }
        //STEP-2 create a new list with random pointers
        curr=head;
        while(curr!=nullptr){
            if(curr->random!=nullptr){
            curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }
        //step-3 separate two arrays
        curr=head;
            Node* newHead=head->next;
            Node* newCurr=curr->next;
        while(curr!=nullptr){
 

            curr->next=newCurr->next;
            curr=curr->next;
            if(curr!=nullptr){
            newCurr->next=curr->next;
            newCurr=newCurr->next;

            }
            

        }
        return newHead;
        }

};
