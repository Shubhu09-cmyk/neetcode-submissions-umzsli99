class Solution {
   // TC O(log n) SC O(1).  Floyd warshell algo
private:
    int nextNum(int n){
        int sum=0;
        while(n){
            int digit=n%10;
            sum+=digit*digit;   //digit square sum
            n=n/10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        int slow=n;
        int fast=nextNum(n);
        while(fast!=1 && slow!=fast){//con1. if fast==1 happy no. ; if sloww==fast then cyclic
            slow=nextNum(slow);
            fast=nextNum(nextNum(fast));
        }
        return fast==1;
    }
};
