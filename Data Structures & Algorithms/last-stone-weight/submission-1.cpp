class Solution {
    /*
    2. Main loop
Each iteration:
Extract two max elements → pop() twice → O(log n) each
Possibly insert one element → push() → O(log n)
So each "smash" operation costs:
O(log n)
Worst case:
You reduce the heap size from n to 1
Number of operations ≈ n−1
So total:
O(nlogn)
📦 Space Complexity
The heap stores all stones in the worst case.
So space is:
O(n)
*/
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(),stones.end());//max heap  Top = largest stone
        while(pq.size()>1){
            int y=pq.top();
            pq.pop();
            int x=pq.top();
            pq.pop();
            if((y-x)!=0){
                pq.push(y-x);
            }
        }
        return pq.empty()? 0 : pq.top() ;
    }
};
