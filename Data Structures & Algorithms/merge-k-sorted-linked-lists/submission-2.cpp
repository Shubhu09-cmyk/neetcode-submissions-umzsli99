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
    
    //Recursive divide Time O(Nlogk). space O(logk)

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
        {
            return nullptr;
        }        
        return mergekSortedLinkedlistHelper(lists,0,lists.size()-1);//start=0;end=lists.length-1
    }

/*In C++, if this function is outside the class, it needs to be declared before it is used or made a static/helper function inside the class.
Currently mergeKLists calls it before it's defined.
Fix:
Move mergekSortedLinkedlistHelper inside the Solution class OR declare it first.
Example (inside the class):
*/
private:
ListNode* mergekSortedLinkedlistHelper(vector<ListNode*>& lists,int start, int end){
if(start==end){  //single list in array
return lists[start];
}

if(start+1==end){ //if 2 lists in array
    return merge2lists(lists[start],lists[end]);
}

//if more than 2 lists are there
int mid=start+(end-start)/2;

ListNode* left=mergekSortedLinkedlistHelper(lists,start,mid);  //start=0;end=mid
ListNode* right=mergekSortedLinkedlistHelper(lists,mid+1,end);  //start=mid+1;end=lists.size()-1
return merge2lists(left,right);
}

ListNode* merge2lists(ListNode* l1, ListNode* l2){
   ListNode* dummy=new ListNode(0);
   ListNode* current=dummy;

while(l1!=nullptr && l2!=nullptr){
   if(l1->val<l2->val){
    current->next=l1;
    l1=l1->next;
   } else{
    current->next=l2;
    l2=l2->next;
   }
   current=current->next;
}
   current->next=(l1!=nullptr)?l1:l2;

   return dummy->next;
}
};

//100 percent correct
/*
class Solution {
    ////Recursive divide Time O(Nlogk). space O(logk)
private:
    ListNode* mergeKsorted(vector<ListNode*>& lists,int start,int end){
        if(start==end) return lists[start];//single list
        if(end==start+1) return mergeTwoSorted(lists[start],lists[end]);//if two 
        int mid=start+(end-start)/2;
        ListNode* left=mergeKsorted(lists,start,mid);
        ListNode* right=mergeKsorted(lists,mid+1,end);
        return mergeTwoSorted(left,right);
    }
    ListNode* mergeTwoSorted(ListNode* l1,ListNode* l2){//After merging, your original list heads may get modified in unexpected ways during recursion.

        ListNode* dummy=new ListNode(0);  //ListNode dummy(0);to avoid memory leak
        ListNode* temp=dummy;    //ListNode* temp = &dummy; //You allocate memory with new You never delete it
        
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val<l2->val){
                temp->next=l1;
                l1=l1->next;
            }else{
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
        temp->next=(l1!=nullptr)?l1:l2;
        return dummy->next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;//if 0 list.  lists.empty()
        return mergeKsorted(lists,0,lists.size()-1);//start 0 end= last       
    }
};
*/

