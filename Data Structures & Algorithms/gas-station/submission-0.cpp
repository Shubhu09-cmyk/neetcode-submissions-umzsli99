class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int TotalGas=0; int TotalCost=0;
        for(int i=0;i<gas.size();i++){
            TotalGas+=gas[i];
            TotalCost+=cost[i];
        }
        if(TotalGas<TotalCost) return -1;
        
       int currGas=0;
       int startIndex=0;
       for(int i=0;i<gas.size();i++){
         currGas+=gas[i]-cost[i];

         if(currGas<0){
            startIndex=i+1;
            currGas=0;
         }
       }
      return startIndex;  
    }
};
