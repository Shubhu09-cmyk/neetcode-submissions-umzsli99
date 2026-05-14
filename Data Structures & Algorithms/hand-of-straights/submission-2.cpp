class Solution {
    //TC O(n log n ). Space O(n).  sorting(nlogn) hashmap(1)
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
   if(hand.size()%groupSize!=0) return false;  //return false if we can't form groups
   unordered_map<int,int> freq;
   for(int x:hand){
    freq[x]++; //calculate freq
   }
   //sort the hand array
   sort(hand.begin(),hand.end());
   for(int x:hand){
    if(freq[x]==0) continue;//element already used
    for(int i=0;i<groupSize;i++){
        int curr=x+i;
        if(freq[curr]==0) return false;//required consecutive card does not exiost

        freq[curr]--;
    }
   }
    return true;
    }
};