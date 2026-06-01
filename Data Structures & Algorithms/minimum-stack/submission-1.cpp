class MinStack {

public:
             vector<int>v;
             vector<int>pre_min;

    MinStack() {
             
        
    }
    
    void push(int val) {

        v.push_back(val);
        if(!pre_min.empty())
        {  
               auto end_ptr = pre_min.end() - 1;
               pre_min.push_back( min(*end_ptr,val));
            
        }
        else
        {
            pre_min.push_back(val);
        }
    }
    
    void pop() {

        v.pop_back();
        pre_min.pop_back();

        
    }
    
    int top() {
               auto end_ptr = v.end() - 1;
               return *end_ptr;

        
    }
    
    int getMin() {

        auto end_ptr = pre_min.end() - 1;
        return *end_ptr;
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