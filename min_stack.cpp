//6-1-2026 2
class MinStack {
public:
    vector<std::pair<int,int>> stack;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(this->stack.empty()){
            this->stack.push_back(std::pair<int,int>{val,val});
        }else{
            this->stack.push_back(std::pair<int,int>{val,
            std::min(val,this->stack[this->stack.size()-1].second)
            });
        }
    }
    
    void pop() {
        if(!this->stack.empty()){
            this->stack.pop_back();
        }
    }
    
    int top() {
        if(this->stack.empty()){
            return INT_MAX;
        }else{
            return this->stack[this->stack.size()-1].first;
        }
    }
    
    int getMin() {
        if(this->stack.empty()){
            return INT_MAX;
        }else{
            return this->stack[this->stack.size()-1].second;
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */