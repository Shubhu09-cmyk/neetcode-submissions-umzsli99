class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int,double>> cars;  //to store position and time to reach target
    for(int i=0;i<position.size();i++){
        cars.push_back({
            position[i], (double (target-position[i])/speed[i])
        });
        //put cars in descending order of position
        
    }
        sort(cars.rbegin(),cars.rend());
        int fleat=0;
        double max_time=0;
        for(auto c:cars){
            if(c.second>max_time){
                fleat++;
                max_time=c.second;
            }
        }
          
    return fleat;
    }
};
