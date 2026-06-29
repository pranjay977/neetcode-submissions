class MinStack {
public:
stack<pair<int,int>> stck;
    MinStack() {

        
    }
    
    void push(int val) {
        if(stck.empty()) stck.push({val,val});
        else stck.push({val,min(stck.top().second,val)});
    }
    
    void pop() {
        if(stck.empty()) return;
        stck.pop();
    }
    
    int top() {
        if(stck.empty()) return 0;
        return stck.top().first;
        
    }
    
    int getMin() {
        if(stck.empty()) return 0;
        return stck.top().second;
        
    }
};
