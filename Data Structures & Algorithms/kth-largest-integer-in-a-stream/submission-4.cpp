/*
Constructor
KthLargest(int k, vector<int>& nums)
Each insertion into the heap takes O(log k).
We process all n elements in nums.
So:
O(nlogk)
Space complexity:
O(k)

Operations:add
Push into heap → O(log k)
Possibly pop smallest → O(log k)
Overall:
O(logk)
Space complexity remains:
O(k)
since heap size is capped at k.
*/
class KthLargest {
public:
priority_queue<int,vector<int>,greater<int>> minHeap;
int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int num :nums){
            minHeap.push(num);
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
       
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size()>k){
            minHeap.pop();
        }
       return minHeap.top(); 
    }
};
