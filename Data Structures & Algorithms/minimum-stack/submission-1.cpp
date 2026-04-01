class MinStack {
public:
    stack<pair<int,int>> s;   //t O(N), Space O(2n)
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push({val,val});
        }else{
            s.push({val,min(val,s.top().second)});
        }
    }
    
    void pop() {
    if(!s.empty()){
        s.pop();
    }
        
    }
    
    int top() {
       return s.top().first;
        
    }
    
    int getMin() {
       return s.top().second;
         }
};
